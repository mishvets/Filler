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
# define FILLER_H

# include "../libft/libft.h"

typedef struct			s_coordinate
{
	int					x;
	int					y;
}						t_coordinate;

typedef struct			s_frag_point
{
	t_coordinate		point;
	struct s_frag_point	*next;
}						t_frag_point;

typedef struct			s_frag
{
	t_coordinate		size_f;
	t_frag_point		*start;
}						t_frag;

typedef struct			s_player
{
	char				p;
	char				opp;
	t_coordinate		size_m;
	char				**map;
	t_frag				f;
}						t_player;

int						ft_find_place_for_frag(t_player user,
						t_coordinate *place);
t_frag_point			*ft_pointaddr(t_frag_point *alst, t_frag_point *new);
int						ft_player(char *line, t_player *user, int fd);
void					ft_read_size(char *line, t_coordinate *size);
int						ft_read_map(char ***map, t_coordinate *size, int fd);
int						ft_read_frag(t_frag_point **start, t_coordinate *size_f,
						int fd);
#endif
