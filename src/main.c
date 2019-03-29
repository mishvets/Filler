/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:29:39 by mshvets           #+#    #+#             */
/*   Updated: 2019/02/27 18:29:41 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

t_frag_point	*ft_pointaddr(t_frag_point *alst, t_frag_point *new)
{
	t_frag_point	*crawler;

	crawler = alst;
	if (crawler)
	{
		while (crawler->next)
			crawler = crawler->next;
		crawler->next = new;
	}
	else
		alst = new;
	return (alst);
}

void			ft_del_frag(t_frag_point **start)
{
	t_frag_point *crawler;

	while (*start)
	{
		crawler = *start;
		*start = (*start)->next;
		free(crawler);
	}
}

int				main(void)
{
	int				fd;
	char			*line;
	t_player		user;
	t_coordinate	*answer;

	line = NULL;
	user.f.start = NULL;
	if (!(fd = 0) && !ft_player(line, &user, fd))
		return (1);
	if (!(answer = (t_coordinate *)malloc(sizeof(t_coordinate))))
		return (1);
	while (get_next_line(fd, &line) > 0)
	{
		ft_read_size(line, &user.size_m);
		if (!ft_read_map(&user.map, &user.size_m, fd))
			return (1);
		if (!ft_read_frag(&user.f.start, &user.f.size_f, fd))
			return (1);
		ft_find_place_for_frag(user, answer);
		ft_printf("%i %i\n", answer->y, answer->x);
		ft_doublstrdel(&user.map, user.size_m.y);
		ft_del_frag(&user.f.start);
	}
	return (0);
}
