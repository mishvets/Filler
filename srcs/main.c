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

#include "../includes/filler.h"
#include <fcntl.h>//

int     ft_player(char *line, t_player *user, int fd)
{
    int i;

    i = 0;
    while (i++ < 3)
    {
        get_next_line(fd, &line);
        if (ft_strstr(line, "mshvets.filler"))
            break ;
		ft_strdel(&line);
    }
	ft_strdel(&line);
    if (i == 1)
        user->p = 'O';
    else if (i == 2)
        user->p = 'X';
    else
        return (0);
    return (1);
}

void	ft_skip_line(int fd)
{
	char *trash;

	get_next_line(fd, &trash);
	ft_strdel(&trash);
}

void   ft_readSize(char *line, t_coordinate *size, int fd)
{
    int i;

    i = 0;
    while(!ft_isdigit(line[i]))
        ++i;
	(*size).y = ft_atoi(&line[i]);
    i = i + ft_numinstr(&line[i]) + 1;
	(*size).x = ft_atoi(&line[i]);
    ft_strdel(&line);
}

int 	ft_readMap(char ***map, t_coordinate *size, int fd)
{
	int i;

	i = 0;
	(*map) = (char **)malloc(sizeof(char *) * size->x);
	while (i < size->y)
	{
		if (get_next_line(fd, &(*map)[i]) < 0)
			return (0);
//		ft_printf("%s\n", (*map)[i]);
		++i;
	}
	return (1);
}

t_fragPoint	*ft_pointaddr(t_fragPoint *alst, t_fragPoint *new)
{
	t_fragPoint	*crawler;

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

int 	ft_readFrag(t_fragPoint **start, t_coordinate *sizeF, int fd)
{
	int			i;
	int			j;
	char 		*line;
	t_fragPoint	*crawler;

	i = 0;
	crawler = *start;
	if((get_next_line(fd, &line) < 0))
		return (0);
	ft_readSize(line, sizeF, fd);
	while (i < sizeF->y)
	{
		if (get_next_line(fd, &line) < 0)
			return (0);
		j = 0;
		while (ft_strchr(&(line[j]), '*'))
		{
			j = ft_strchr(&(line[j]), '*') - line;
			if (!(crawler = (t_fragPoint *)malloc(sizeof(t_fragPoint))))
				return (0);
			crawler->next = NULL;
			crawler->point.x = j;
			crawler->point.y = i;
			*start = ft_pointaddr(*start, crawler);
			++j;
		}
		++i;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (1);
}

void	ft_doublstrdel(char ***map, int y) // create singl function
{
	int i;

	i = 0;
	while (i < y)
	{
		ft_strdel(&(*map)[i]);
		++i;
	}
	free(&(**map));
	*map = NULL;
}

int     main()
{
    char		*line;
    t_player    user;
	t_coordinate *answer;

    line = NULL;
    user.F.start = NULL;
	int fd = open("../test", O_RDONLY);
    if (!ft_player(line, &user, fd))
        return (1);
	if (!(answer = (t_coordinate *)malloc(sizeof(t_coordinate))))
		return (0);
    while (get_next_line(fd, &line))
    {
        ft_readSize(line, &user.sizeM, fd);
		ft_skip_line(fd);
        if(!ft_readMap(&user.map, &user.sizeM, fd))
        	return(1);
		if(!ft_readFrag(&user.F.start, &user.F.sizeF, fd))
			return (1);
		if (!ft_find_place_for_frag(user, answer))
			ft_printf("0 0\n");
		else//answer
			ft_printf("%i %i\n", answer->x, answer->y);
    }
    ft_doublstrdel(&user.map, user.sizeM.y);
    system("leaks Filler -q");
    return(0);
}