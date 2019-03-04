/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 21:12:49 by mshvets           #+#    #+#             */
/*   Updated: 2019/03/01 21:12:51 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "../libft/libft.h"

typedef struct      	s_coordinate
{
	int 				x;
	int 				y;
}                   	t_coordinate;

typedef struct			s_fragPoint
{
	t_coordinate		point;
	struct s_fragPoint	*next;
}						t_fragPoint;

typedef struct			s_frag
{
	t_coordinate		sizeF;
	t_fragPoint			*start;
}						t_frag;

typedef struct      	s_player
{
	char            	p;
	t_coordinate		sizeM;
	char 				**map;
	t_frag				F;
}                   	t_player;

int						ft_find_place_for_frag(t_player user);

#endif //FILLER_FILLER_H
