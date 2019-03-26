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

unsigned int	func(t_player user, t_coordinate p, t_coordinate limit, int fd1)//del fd1
{
	t_coordinate	l1;
	t_coordinate	l2;
	t_coordinate	inc;
	t_coordinate	stop;
	unsigned int	len1;
	unsigned int	len2;

	ft_putstr_fd("func start\n", fd1);//
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
	ft_putstr_fd("p.x = ", fd1);//
	ft_putstr_fd(ft_itoa(p.x), fd1);//
	ft_putstr_fd(", p.y = ", fd1);//
	ft_putstr_fd(ft_itoa(p.y), fd1);//
	ft_putstr_fd("\n", fd1);//
	ft_putstr_fd("limit.x = ", fd1);//
	ft_putstr_fd(ft_itoa(limit.x), fd1);//
	ft_putstr_fd(", limit.y = ", fd1);//
	ft_putstr_fd(ft_itoa(limit.y), fd1);//
	ft_putstr_fd("\n\n", fd1);//
	while (!stop.x || !stop.y)
	{
		ft_putstr_fd("l1.x = ", fd1);//
		ft_putstr_fd(ft_itoa(l1.x), fd1);//
		ft_putstr_fd(", l1.y = ", fd1);//
		ft_putstr_fd(ft_itoa(l1.y), fd1);//
		ft_putstr_fd("\n", fd1);//
		ft_putstr_fd("l2.x = ", fd1);//
		ft_putstr_fd(ft_itoa(l2.x), fd1);//
		ft_putstr_fd(", l2.y = ", fd1);//
		ft_putstr_fd(ft_itoa(l2.y), fd1);//
		ft_putstr_fd("\n", fd1);//
		if (user.map[l1.y][l1.x] == user.opp)
		{
			ft_putstr_fd("user.map[l1.y][l1.x] - ", fd1);//
			ft_putstr_fd(&user.map[l1.y][l1.x], fd1);//
			ft_putstr_fd("\n", fd1);//
			len1 = ft_pow((l1.y - p.y), 2) + ft_pow((l1.x - p.x), 2);
		}
		if (user.map[l2.y][l2.x] == user.opp)
		{
			ft_putstr_fd("user.map[l2.y][l2.x] - ", fd1);//
			ft_putstr_fd(&user.map[l2.y][l2.x], fd1);//
			ft_putstr_fd("\n", fd1);//
			len2 = ft_pow((l2.y - p.y), 2) + ft_pow((l2.x - p.x), 2);
		}
		if (len1 != 1000000 || len2 != 1000000)
		{
			ft_putstr_fd("len1 = ", fd1);
			ft_putstr_fd(ft_itoa(len1), fd1);//
			ft_putstr_fd(", len2 = ", fd1);
			ft_putstr_fd(ft_itoa(len2), fd1);//
			ft_putstr_fd("\n", fd1);//
			return (len1 < len2 ? len1 : len2);
		}

		if (l1.x != limit.x)
			l1.x += inc.x;
		else
			stop.x = 1;
		if (l2.y != limit.y)
			l2.y += inc.y;
		else
			stop.y = 1;
		ft_putstr_fd("Next iter\n", fd1);//
	}
	return (len1);
}

unsigned int	ft_func(t_player user, t_coordinate p, t_coordinate	limit, int fd1) // del fd1
{
	unsigned int	len_tmp;
	t_coordinate	inc;
	t_coordinate	finish;
	t_coordinate	stop;


	ft_putstr_fd("ft_func start\n", fd1);//
	finish.x = p.x;
	finish.y = p.y;
	inc.x = finish.x > limit.x ? -1 : 1;
	inc.y = finish.y > limit.y ? -1 : 1;
	ft_putstr_fd("limit.x = ", fd1);//
	ft_putstr_fd(ft_itoa(limit.x), fd1);//
	ft_putstr_fd(", limit.y = ", fd1);//
	ft_putstr_fd(ft_itoa(limit.y), fd1);//
	ft_putstr_fd("\n\n", fd1);//
	stop.x = 0;
	stop.y = 0;
	len_tmp = 1000000;
	while (!stop.x || !stop.y)
	{
		if ((len_tmp = func(user, p, finish, fd1)) < 1000000)
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


unsigned int	ft_lenmin(t_player user, int p_column, int p_row, int fd1)//del fd1
{
	unsigned int	len_tmp;
	unsigned int	len;
	t_coordinate	limit;
	t_coordinate	p;

	ft_putstr_fd("ft_lenmin start\n", fd1);//
	p.x = p_column;
	p.y = p_row;
	ft_putstr_fd(ft_itoa(p.y), fd1);//
	len = 1000000;
	limit.x = 0;
	limit.y = 0;
	if (len > (len_tmp = ft_func(user, p, limit, fd1)))
		len = len_tmp;
	limit.x = user.sizeM.x - 1;
	limit.y = 0;
	if (len > (len_tmp = ft_func(user, p, limit, fd1)))
		len = len_tmp;
	limit.x = user.sizeM.x - 1;
	limit.y = user.sizeM.y - 1;
	if (len > (len_tmp = ft_func(user, p, limit, fd1)))
		len = len_tmp;
	limit.x = 0;
	limit.y = user.sizeM.y - 1;
	if (len > (len_tmp = ft_func(user, p, limit, fd1)))
		len = len_tmp;
	return (len);
}

//unsigned int	ft_lenmin(t_player user, int p_column, int p_row, int fd1)//del fd1
//{
//	int				map_row;
//	int				map_column;
//	unsigned int	len_tmp;
//	unsigned int	len;
//
//	map_row = 0;
//	len = 1000000;
//	while (map_row < user.sizeM.y)
//	{
//		map_column = 0;
//		while (map_column < user.sizeM.x)
//		{
//			if ((user.map[map_row][map_column] != user.p) &&
//				(user.map[map_row][map_column] != '.')) // user.map[map_row][map_column] == user.opp
//			{
//
//				len_tmp = ft_pow((map_row - p_row), 2) + ft_pow((map_column - p_column), 2);
//				ft_putstr_fd("map_row = ", fd1);// у где противник
//				ft_putstr_fd(ft_itoa(map_row), fd1);//
//				ft_putstr_fd("\n", fd1);//
//				ft_putstr_fd("map_column = ", fd1);// х где противник
//				ft_putstr_fd(ft_itoa(map_column), fd1);//
//				ft_putstr_fd("\n", fd1);//
//				ft_putstr_fd("p_row = ", fd1);//map_row + crawler->point.y
//				ft_putstr_fd(ft_itoa(p_row), fd1);//
//				ft_putstr_fd("\n", fd1);//
//				ft_putstr_fd("p_column = ", fd1);//map_column + crawler->point.x
//				ft_putstr_fd(ft_itoa(p_column), fd1);//
//				ft_putstr_fd("\n", fd1);//
//				ft_putstr_fd("len_tmp = ", fd1);//
//				ft_putstr_fd(ft_itoa(len_tmp), fd1);//
//				ft_putstr_fd("\n", fd1);//
//				if (len > len_tmp)
//					len = len_tmp;
//			}
//			++map_column;
//		}
//		++map_row;
//	}
//	ft_putstr_fd("-----------len = ", fd1);//
//	ft_putstr_fd(ft_itoa(len), fd1);//
//	ft_putstr_fd("\n", fd1);//
//	return (len);
//}

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
			if (user.map[map_row + crawler->point.y][map_column + crawler->point.x] == user.opp)
				return (0);
			if (user.map[map_row + crawler->point.y][map_column + crawler->point.x] == user.p ||
			user.map[map_row + crawler->point.y][map_column + crawler->point.x] == ft_tolower(user.p))
			{
				if (overlay)
					return (0);
				else
					overlay = 1;
			}
//			if (user.map[map_row + crawler->point.y][map_column + crawler->point.x] == user.p ||
//					user.map[map_row + crawler->point.y][map_column + crawler->point.x] == ft_tolower(user.p))
//			{
//				if (overlay)
//					return (0);
//				else
//					overlay = 1;
//				*len += ft_lenmin(user, map_column + crawler->point.x, map_row + crawler->point.y, fd1);
//			}
//			else if (user.map[map_row + crawler->point.y][map_column + crawler->point.x] != '.')
//				return (0);
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
	crawler = user.F.start;
	while (crawler)
	{
		*len += ft_lenmin(user, map_column + crawler->point.x, map_row + crawler->point.y, fd1);
		crawler = crawler->next;
	}
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
