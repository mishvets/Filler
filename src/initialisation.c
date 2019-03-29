/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:30:39 by mshvets           #+#    #+#             */
/*   Updated: 2019/03/29 17:15:27 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int			ft_player(char *line, t_player *user, int fd)
{
	int	player;

	if (get_next_line(fd, &line) < 0)
		return (0);
	player = ft_atoi(line + 10);
	if (player == 1)
	{
		user->p = 'O';
		user->opp = 'X';
	}
	else if (player == 2)
	{
		user->p = 'X';
		user->opp = 'O';
	}
	ft_strdel(&line);
	return (1);
}

void		ft_read_size(char *line, t_coordinate *size)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]))
		++i;
	(*size).y = ft_atoi(&line[i]);
	i = i + ft_numinstr(&line[i]) + 1;
	(*size).x = ft_atoi(&line[i]);
	ft_strdel(&line);
}

int			ft_read_map(char ***map, t_coordinate *size, int fd)
{
	int		i;
	char	*line;

	i = 0;
	if (!get_next_line(fd, &line))
		return (0);
	else
		ft_strdel(&line);
	(*map) = (char **)malloc(sizeof(char *) * size->x);
	while (i < size->y)
	{
		if (get_next_line(fd, &line) < 0)
			return (0);
		(*map)[i] = ft_strdup(ft_strchr(line, ' ') + 1);
		ft_strdel(&line);
		++i;
	}
	return (1);
}

static int	ft_init_frag(t_frag_point *crawler, t_frag_point **start,
		t_coordinate *i)
{
	if (!(crawler = (t_frag_point *)malloc(sizeof(t_frag_point))))
		return (0);
	crawler->next = NULL;
	crawler->point.x = i->x;
	crawler->point.y = i->y;
	*start = ft_pointaddr(*start, crawler);
	++(i->x);
	return (1);
}

int			ft_read_frag(t_frag_point **start, t_coordinate *size_f, int fd)
{
	t_coordinate	i;
	char			*line;
	t_frag_point	*crawler;

	i.y = 0;
	crawler = *start;
	if ((get_next_line(fd, &line) < 0))
		return (0);
	ft_read_size(line, size_f);
	while (i.y < size_f->y)
	{
		if (get_next_line(fd, &line) < 0)
			return (0);
		i.x = 0;
		while (ft_strchr(&(line[i.x]), '*'))
		{
			i.x = ft_strchr(&(line[i.x]), '*') - line;
			if (!ft_init_frag(crawler, start, &i))
				return (0);
		}
		++i.y;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}
