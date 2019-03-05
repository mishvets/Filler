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
#include <stdio.h>//
int fd1;

int     ft_player(char *line, t_player *user, int fd)
{
//    int i;
//
//    i = 0;
//    while (i++ < 2)
//    {
//        if (get_next_line(fd, &line) < 0)
//        	return (0);
//		//
//		ft_putstr_fd(line, fd1);//
//		ft_putstr_fd("\n", fd1);//
//		//
//        if (ft_strstr(line, "mshvets.filler"))
//		{
//			if (i == 1)
//				user->p = 'O';
//			else if (i == 2)
//				user->p = 'X';
//		}
//		ft_strdel(&line);
//    }
//	ft_strdel(&line);
	int	player;


	if (get_next_line(fd, &line) < 0)
        	return (0);
	//
	ft_putstr_fd(line, fd1);
	ft_putstr_fd("\n", fd1);
	//
	player = ft_atoi(ft_strstr(line, "$$$ exec p"));
	if (player == 1)
		user->p = 'O';
	else if (player == 2)
		user->p = 'X';
	ft_strdel(&line);
    return (1);
}

void	ft_skip_line(int fd)
{
	char *trash;

	get_next_line(fd, &trash);
	//
	ft_putstr_fd(trash, fd1);//
	ft_putstr_fd("\n", fd1);//
	//
	ft_strdel(&trash);
}

void   ft_readSize(char *line, t_coordinate *size)
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
	int		i;
	char	*line;

	i = 0;
	(*map) = (char **)malloc(sizeof(char *) * size->x);

	while (i < size->y)
	{
//		if (get_next_line(fd, &(*map)[i]) < 0)
//			return (0);
		if (get_next_line(fd, &line) < 0)
			return (0);
		(*map)[i] = ft_strdup(ft_strchr(line, ' ') + 1);
		ft_strdel(&line);
		//
		ft_putstr_fd((*map)[i], fd1);//
		ft_putstr_fd("\n", fd1);//
		//
//		ft_printf("%s\n", (*map)[i]);
		++i;
	}
	ft_putstr_fd("______________^^^", fd1);//
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
	//
	ft_putstr_fd(line, fd1);//
	ft_putstr_fd("\n", fd1);//
	//
	ft_readSize(line, sizeF);
	ft_putstr_fd("size frag >> ", fd1);//
	ft_putnbr_fd(sizeF->y ,fd1);//
	ft_putstr_fd("\n", fd1);//
	while (i < sizeF->y)
	{
		if (get_next_line(fd, &line) < 0)
			return (0);
		//
		ft_putstr_fd(line, fd1);//
		ft_putstr_fd("\n", fd1);//
		//
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

//ft_delFrag(&user.F.start)
//{
//	void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
//	{
//		t_list *crawler;
//
//		while (*alst)
//		{
//			crawler = (*alst);
//			*alst = (*alst)->next;
//			ft_lstdelone(&crawler, del);
//		}
//	}
//}

int     main()
{
    char		*line;
    t_player    user;
	t_coordinate *answer;

    line = NULL;
    user.F.start = NULL;
	fd1 = open("res.txt", O_RDWR);
//	fd1 = 0;
//	ft_printf("%d", fd1);
//	int fd = open("../test", O_RDONLY);
	int fd = 0;


//	get_next_line(fd, &line);
    if (!ft_player(line, &user, fd))
        return (1);
	if (!(answer = (t_coordinate *)malloc(sizeof(t_coordinate))))
		return (1);
    while (get_next_line(fd, &line) > 0)
    {
//		ft_printf("%s ----\n", line);
		//
//		dprintf(fd1,"%s", line);//
//		dprintf(fd1, "\n");//
		//
		ft_putstr_fd(line, fd1);
		ft_putstr_fd("\n", fd1);
		//
    	ft_readSize(line, &user.sizeM);
		ft_skip_line(fd);
        if( !ft_readMap(&user.map, &user.sizeM, fd))
        	return(1);
		if (!ft_readFrag(&user.F.start, &user.F.sizeF, fd))
			return (1);
		if (!ft_find_place_for_frag(user, answer))//segfault
			ft_printf("0 0\n");
		else//answer
			ft_printf("%i %i\n", answer->y, answer->x);
//		ft_doublstrdel(&user.map, user.sizeM.y);
//		user.F.start = NULL;//LEAKS!!!
//		ft_delFrag(&user.F.start = NULL);
	}
//    system("leaks Filler -q");
    return(0);
}