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

void    first_call(char *line, t_player *user)
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

int main()
{
    char		*line;
    t_player    user;

    first_call(line);
    while (get_next_line(1, &line))
    {

    }
    return(0);
}