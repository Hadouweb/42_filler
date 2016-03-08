#ifndef VISU_H
# define VISU_H

#include "libft.h"
#include <stdio.h>
#include <ncurses.h>

typedef struct 		s_player
{
	int				id;
	char			*name;
}					t_player;

typedef struct  	s_app
{
	t_player		p1;
	t_player		p2;
}					t_app;

#endif