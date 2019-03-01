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

int     first_call(char *line, t_player *user)
{
    int i;

    i = 0;
    while (i++ < 3)
    {
        get_next_line(1, &line);
        if (ft_strstr(line, "mshvets.filler"))
            break ;
    }
    if (i == 1)
        user->p = 'O';
    else if (i == 2)
        user->p = 'X';
    else
        return (0);
    return (1);
}

void	ft_skip_line()
{
	char *trash;

	get_next_line(1, &trash);
	ft_strdel(&trash);
}

void    ft_readSize(char *line, t_player *user)
{
    int i;

    i = 0;
    while(!ft_isalnum(line[i]))
        ++i;
    user->sizeF->x = ft_atoi(&line[i]);
    i = i + ft_numinstr(&line[i]) + 1;
    user->sizeF->y = ft_atoi(&line[i])
    ft_strdel(*line);
    ft_skip_line();
}

int     main()
{
    char		*line;
    t_player    user;

    if (!first_call(line))
        return (0);
    while (get_next_line(1, &line))
    {
        ft_readSize(line, &user);
        ft_readField();
    }
    return(0);
}