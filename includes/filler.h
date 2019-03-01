//
// Created by mshvets on 28.02.2019.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

#include "../libft/libft.h"

typedef struct      s_coordinates
{
	int 			x;
	int 			y;
}                   t_coordinates;

typedef struct      s_player
{
    char            p;
	t_coordinates	*sizeF;
}                   t_player;

#endif //FILLER_FILLER_H
