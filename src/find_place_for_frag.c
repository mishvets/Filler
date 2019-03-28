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

unsigned int	ft_lenmin(t_player user, int p_col, int p_row)
{
	int				map_row;
	int				map_col;
	unsigned int	len_tmp;
	unsigned int	len;

	map_row = 0;
	len = 100000000;
	while (map_row < user.sizeM.y)
	{
		map_col = 0;
		while (map_col < user.sizeM.x)
		{
			if (user.map[map_row][map_col] == user.opp
			|| user.map[map_row][map_col] == ft_tolower(user.opp))
			{
				len_tmp = ft_pow((map_row - p_row), 2)
				+ ft_pow((map_col - p_col), 2);
				if (len > len_tmp)
					len = len_tmp;
			}
			++map_col;
		}
		++map_row;
	}
	return (len);
}

int	ft_check_frag(t_player user, int map_col, int map_row, unsigned int *len)
{
	t_fragPoint *crawler;
	int			overlay;

	overlay = 0;
	*len = 0;
	crawler = user.F.start;
	while (crawler)
	{
		if ((map_col + crawler->point.x) < user.sizeM.x
			&& (map_row + crawler->point.y) < user.sizeM.y)
		{
			if (user.map[map_row + crawler->point.y][map_col + crawler->point.x] == user.opp
			|| user.map[map_row + crawler->point.y][map_col + crawler->point.x]
			== ft_tolower(user.opp))
				return (0);
			if (user.map[map_row + crawler->point.y]
			[map_col + crawler->point.x] == user.p)
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
		*len += ft_lenmin(user, map_col + crawler->point.x,
				map_row + crawler->point.y);
		crawler = crawler->next;
	}
	return (1);
}

int ft_find_place_for_frag(t_player user, t_coordinate *place)
{
	int map_row;
	int map_col;
	unsigned int len;
	unsigned int len_tmp;

	map_row = 0;
	place->x = 0;
	place->y = 0;
	len = 100000000;
	while (map_row < user.sizeM.y)
	{
		map_col = 0;
		while (map_col < user.sizeM.x)
		{
			if (ft_check_frag(user, map_col, map_row, &len_tmp))
			{
				if (len > (len_tmp))
				{
					len = len_tmp;
					place->x = map_col;
					place->y = map_row;
				}
			}
			++map_col;
		}
		++map_row;
	}
	return (1);
}
