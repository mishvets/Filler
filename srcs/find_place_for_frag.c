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

int	ft_check_frag(t_player user, int map_column, int map_row)
{
	t_fragPoint *crawler;
	int			overlay;

	overlay = 0;
	crawler = user.F.start;
	while (crawler)
	{
		if ((map_column + crawler->point.x) < (user.sizeM.x)
			|| (map_row + crawler->point.y) < user.sizeM.y)
		{
			if (user.map[map_row + crawler->point.y][map_column + crawler->point.x] == user.p ||
					user.map[map_row + crawler->point.y][map_column + crawler->point.x] == ft_tolower(user.p))
			{
				if (overlay)
					return (0);
				else
					overlay = 1;
			}
			else if (user.map[map_row + crawler->point.y][map_column + crawler->point.x] != '.')
				return (0);
		}
		crawler = crawler->next;
	}
	if (!overlay)
		return (0);
	return (1);
}

int ft_find_place_for_frag(t_player user, t_coordinate *place)
{
	int map_row;
	int map_column;
//	t_coordinate *place;

	map_row = 0;
	while (map_row < user.sizeM.y)
	{
		map_column = 0;
		while (map_column < user.sizeM.x)
		{
			//if (user.map[map_row][map_column] == user.p || user.map[map_row][map_column] == ft_tolower(user.p))
				if (ft_check_frag(user, map_column, map_row))
				{
					place->x = map_column;
					place->y = map_row;
					return (1);
//					if (!(place = (t_coordinate *)malloc(sizeof(t_coordinate))))
//						return (0);
				}
			++map_column;
		}
		++map_row;
	}
	return (0);
}
