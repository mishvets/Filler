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

#include "../includes/filler.h"

unsigned int	func(t_player user, t_coordinate p, t_coordinate limit)
{
	t_coordinate	l1;
	t_coordinate	l2;
	t_coordinate	inc;
	t_coordinate	stop;
	unsigned int	len1;
	unsigned int	len2;

	inc.x = p.x > limit.x ? -1 : 1;
	inc.y = p.y > limit.y ? -1 : 1;
	len1 = 1000000;
	len2 = 1000000;
	l1.x = p.x;
	l1.y = limit.y;
	l2.x = limit.x;
	l2.y = p.y;
	stop.x = 0;
	stop.y = 0;
	while (!stop.x || !stop.y)
	{
		if (user.map[l1.y][l1.x] == user.opp)
			len1 = ft_pow((l1.y - p.y), 2) + ft_pow((l1.x - p.x), 2);
		if (user.map[l2.y][l2.x] == user.opp)
			len2 = ft_pow((l2.y - p.y), 2) + ft_pow((l2.x - p.x), 2);
		if (len1 != 1000000 || len2 != 1000000)
			return (len1 < len2 ? len1 : len2);
		if (l1.x != limit.x)
			l1.x += inc.x;
		else
			stop.x = 1;
		if (l2.y != limit.y)
			l2.y += inc.y;
		else
			stop.y = 1;
	}
	return (len1);
}

unsigned int	ft_func(t_player user, t_coordinate p, t_coordinate	limit)
{
	unsigned int	len_tmp;
	t_coordinate	inc;
	t_coordinate	finish;
	t_coordinate	stop;

	finish.x = p.x;
	finish.y = p.y;
	inc.x = finish.x > limit.x ? -1 : 1;
	inc.y = finish.y > limit.y ? -1 : 1;
	stop.x = 0;
	stop.y = 0;
	len_tmp = 1000000;
	while (!stop.x || !stop.y)
	{
		if ((len_tmp = func(user, p, finish)) < 1000000)
			break;
		if (finish.x != limit.x)
			finish.x += inc.x;
		else
			stop.x = 1;
		if (finish.y != limit.y)
			finish.y += inc.y;
		else
			stop.y = 1;
	}
	return (len_tmp);
}


unsigned int	ft_lenmin(t_player user, int p_column, int p_row)
{
	unsigned int	len_tmp;
	unsigned int	len;
	t_coordinate	limit;
	t_coordinate	p;

	p.x = p_column;
	p.y = p_row;
	len = 1000000;
	limit.x = 0;
	limit.y = 0;
	if (len > (len_tmp = ft_func(user, p, limit)))
		len = len_tmp;
	limit.x = user.sizeM.x - 1;
	limit.y = 0;
	if (len > (len_tmp = ft_func(user, p, limit)))
		len = len_tmp;
	limit.x = user.sizeM.x - 1;
	limit.y = user.sizeM.y - 1;
	if (len > (len_tmp = ft_func(user, p, limit)))
		len = len_tmp;
	limit.x = 0;
	limit.y = user.sizeM.y - 1;
	if (len > (len_tmp = ft_func(user, p, limit)))
		len = len_tmp;
	return (len);
}

int	ft_check_frag(t_player user, int map_column, int map_row, unsigned int *len)//del fd1
{
	t_fragPoint *crawler;
	int			overlay;

	overlay = 0;
	*len = 0;
	crawler = user.F.start;
	while (crawler)
	{
		if ((map_column + crawler->point.x) < user.sizeM.x
			&& (map_row + crawler->point.y) < user.sizeM.y)
		{
			if (user.map[map_row + crawler->point.y]
			[map_column + crawler->point.x] == user.opp)
				return (0);
			if (user.map[map_row + crawler->point.y]
			[map_column + crawler->point.x] == user.p ||
			user.map[map_row + crawler->point.y][map_column + crawler->point.x]
			== ft_tolower(user.p))
			{
				if (overlay)
					return (0);
				else
					overlay = 1;
			}
		}
		else
			return (0);
		crawler = crawler->next;
	}
	if (!overlay)
		return (0);
	crawler = user.F.start;
	while (crawler)
	{
		*len += ft_lenmin(user, map_column + crawler->point.x,
				map_row + crawler->point.y);
		crawler = crawler->next;
	}
	return (1);
}

int ft_find_place_for_frag(t_player user, t_coordinate *place)
{
	int map_row;
	int map_column;
	unsigned int len;
	unsigned int len_tmp;

	map_row = 0;
	place->x = 0;
	place->y = 0;
	len = 1000000000;
	while (map_row < user.sizeM.y)
	{
		map_column = 0;
		while (map_column < user.sizeM.x)
		{
				if (ft_check_frag(user, map_column, map_row, &len_tmp))
				{
					if (len > (len_tmp))
					{
						len = len_tmp;
						place->x = map_column;
						place->y = map_row;
						if (user.sizeM.x > 50 || user.sizeM.y > 50)
							return (1);
					}
				}
			++map_column;
		}
		++map_row;
	}
	return (1);
}
