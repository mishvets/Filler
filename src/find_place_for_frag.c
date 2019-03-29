/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place_for_frag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:07:45 by mshvets           #+#    #+#             */
/*   Updated: 2019/03/04 15:07:47 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static unsigned int	ft_lenmin(t_player user, int p_col, int p_row)
{
	t_coordinate	map;
	unsigned int	len_tmp;
	unsigned int	len;

	map.y = 0;
	len = 100000000;
	while (map.y < user.size_m.y)
	{
		map.x = 0;
		while (map.x < user.size_m.x)
		{
			if (user.map[map.y][map.x] == user.opp
			|| user.map[map.y][map.x] == ft_tolower(user.opp))
			{
				len_tmp = ft_pow((map.y - p_row), 2)
				+ ft_pow((map.x - p_col), 2);
				if (len > len_tmp)
					len = len_tmp;
			}
			++map.x;
		}
		++map.y;
	}
	return (len);
}

static unsigned int	ft_len(t_player user, t_coordinate map)
{
	t_frag_point	*crawler;
	unsigned int	len;

	len = 0;
	crawler = user.f.start;
	while (crawler)
	{
		len += ft_lenmin(user, map.x + crawler->point.x,
				map.y + crawler->point.y);
		crawler = crawler->next;
	}
	return (len);
}

static int			ft_check_frag(t_player u, t_coordinate m, unsigned int *len)
{
	t_frag_point	*c;
	int				overlay;

	overlay = 0;
	*len = 0;
	c = u.f.start;
	while (c)
	{
		if ((m.x + c->point.x) < u.size_m.x && (m.y + c->point.y) < u.size_m.y)
		{
			if (u.map[m.y + c->point.y][m.x + c->point.x] == u.opp
			|| u.map[m.y + c->point.y][m.x + c->point.x] == ft_tolower(u.opp)
			|| (u.map[m.y + c->point.y][m.x + c->point.x] == u.p && overlay))
				return (0);
			if (u.map[m.y + c->point.y][m.x + c->point.x] == u.p)
				overlay = 1;
		}
		else
			return (0);
		c = c->next;
	}
	if (!overlay)
		return (0);
	*len = ft_len(u, m);
	return (1);
}

int					ft_find_place_for_frag(t_player user, t_coordinate *place)
{
	t_coordinate	map;
	unsigned int	len;
	unsigned int	len_tmp;

	place->x = 0;
	place->y = 0;
	len = 100000000;
	map.y = -1;
	while (++map.y < user.size_m.y)
	{
		map.x = -1;
		while (++map.x < user.size_m.x)
		{
			if (ft_check_frag(user, map, &len_tmp))
			{
				if (len > (len_tmp))
				{
					len = len_tmp;
					place->x = map.x;
					place->y = map.y;
				}
			}
		}
	}
	return (1);
}
