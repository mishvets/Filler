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

unsigned int	ft_lenmin(t_player user, int p_column, int p_row, int fd1)//del fd1
{
	int				map_row;
	int				map_column;
	unsigned int	len_tmp;
	unsigned int	len;

	map_row = 0;
	len = 1000000;
	while (map_row < user.sizeM.y)
	{
		map_column = 0;
		while (map_column < user.sizeM.x)
		{
			if ((user.map[map_row][map_column] != user.p) &&
				(user.map[map_row][map_column] != '.'))
			{

				len_tmp = ft_pow((map_row - p_row), 2) + ft_pow((map_column - p_column), 2);
				ft_putstr_fd("map_row = ", fd1);// у где противник
				ft_putstr_fd(ft_itoa(map_row), fd1);//
				ft_putstr_fd("\n", fd1);//
				ft_putstr_fd("map_column = ", fd1);// х где противник
				ft_putstr_fd(ft_itoa(map_column), fd1);//
				ft_putstr_fd("\n", fd1);//
				ft_putstr_fd("p_row = ", fd1);//map_row + crawler->point.y
				ft_putstr_fd(ft_itoa(p_row), fd1);//
				ft_putstr_fd("\n", fd1);//
				ft_putstr_fd("p_column = ", fd1);//map_column + crawler->point.x
				ft_putstr_fd(ft_itoa(p_column), fd1);//
				ft_putstr_fd("\n", fd1);//
				ft_putstr_fd("len_tmp = ", fd1);//
				ft_putstr_fd(ft_itoa(len_tmp), fd1);//
				ft_putstr_fd("\n", fd1);//
				if (len > len_tmp)
					len = len_tmp;
			}
			++map_column;
		}
		++map_row;
	}
	ft_putstr_fd("-----------len = ", fd1);//
	ft_putstr_fd(ft_itoa(len), fd1);//
	ft_putstr_fd("\n", fd1);//
	return (len);
}

int	ft_check_frag(t_player user, int map_column, int map_row, unsigned int *len, int fd1)//del fd1
{
	t_fragPoint *crawler;
	int			overlay;
	int iter = 0; //
//	unsigned int	len_tmp;

	overlay = 0;
//	*len = 1000000;
	*len = 0;
	crawler = user.F.start;
	ft_putstr_fd("->ft_check_frag - start!\n", fd1);//
	while (crawler)
	{
		ft_putstr_fd("--->crawler - ", fd1);//
		ft_putstr_fd(ft_itoa(iter++), fd1);//
		ft_putstr_fd("\n", fd1);//
		if ((map_column + crawler->point.x) < user.sizeM.x
			&& (map_row + crawler->point.y) < user.sizeM.y)
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
//			if (*len > (len_tmp = ft_lenmin(user, map_column, map_row)))
//				*len = len_tmp;
			*len += ft_lenmin(user, map_column + crawler->point.x, map_row + crawler->point.y, fd1);
		}
		else
			return (0);
		crawler = crawler->next;
	}
	ft_putstr_fd("--->Overlay - ", fd1);//
	ft_putstr_fd(ft_itoa(overlay), fd1);//
	ft_putstr_fd("\n", fd1);//
	if (!overlay)
		return (0);
	ft_putstr_fd("--->for y = ", fd1);//
	ft_putstr_fd(ft_itoa(map_row), fd1);//
	ft_putstr_fd(", x = ", fd1);//
	ft_putstr_fd(ft_itoa(map_column), fd1);//
	ft_putstr_fd("\n ----> Len = ", fd1);//
	ft_putstr_fd(ft_itoa(*len), fd1);//
	ft_putstr_fd("\n", fd1);//
	return (1);
}

int ft_find_place_for_frag(t_player user, t_coordinate *place, int fd1)
{
	int map_row;
	int map_column;
	unsigned int len;
	unsigned int len_tmp;
//	t_coordinate *place;

	map_row = 0;
	place->x = 0;
	place->y = 0;
	len = 1000000000;
	ft_putstr_fd("->ft_find_place_for_frag - start!\n", fd1);//
	while (map_row < user.sizeM.y)
	{
		ft_putstr_fd("->row:", fd1);//
		ft_putstr_fd(ft_itoa(map_row), fd1);//
		ft_putstr_fd("\n", fd1);//
		map_column = 0;
		while (map_column < user.sizeM.x)
		{
			ft_putstr_fd("->column:", fd1);//
			ft_putstr_fd(ft_itoa(map_column), fd1);//
			ft_putstr_fd("\n", fd1);//
			//if (user.map[map_row][map_column] == user.p || user.map[map_row][map_column] == ft_tolower(user.p))
				if (ft_check_frag(user, map_column, map_row, &len_tmp, fd1))//del fd1
				{
					if (len > (len_tmp))
					{
						len = len_tmp;
						place->x = map_column;
						place->y = map_row;
						if (user.sizeM.x > 50 || user.sizeM.y > 50)
							return (1);
					}
//					ft_putstr_fd("->ft_find_place_for_frag - find place!\n", fd1);//
//					return (1);
//					if (!(place = (t_coordinate *)malloc(sizeof(t_coordinate))))
//						return (0);
				}
			++map_column;
		}
		++map_row;
	}
//	ft_putstr_fd("->ft_find_place_for_frag - no place!\n", fd1);//
	return (1);
}
