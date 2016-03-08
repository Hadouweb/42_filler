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

typedef struct 		s_board
{
	int				x;
	int				y;
	int				cl;
	char			**tab;
}					t_board;

typedef struct 		s_piece
{
	int				x;
	int				y;
}					t_piece;

typedef struct  	s_app
{
	t_player		p1;
	t_player		p2;
	t_board			b;
	t_piece			p;
	t_player		cp;
	int				m;
	int				line;
	t_list			*list_tmp;
}					t_app;

#endif