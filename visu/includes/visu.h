#ifndef VISU_H
# define VISU_H

#include "libft.h"
#include <stdio.h>
#include <ncurses.h>

# define IS_RUN 0

typedef struct 		s_player
{
	int				id;
	char			*name;
}					t_player;

typedef struct 		s_board
{
	int				x;
	int				y;
	int				current_line;
	char			**tab;
}					t_board;

typedef struct 		s_piece
{
	int				x;
	int				y;
	int				current_line;
	char			**tab;
}					t_piece;

typedef struct 		s_render
{
	WINDOW			*w_left;
	WINDOW			*w_right;
	int				run;
}					t_render;

typedef struct  	s_app
{
	t_player		p1;
	t_player		p2;
	t_board			board;
	t_piece			piece;
	t_player		current_player;
	int				mode;
	int				line;
	t_list			*list_tmp;
	t_render		render;
	int				is_finish;
	int				p1_score;
	int				p2_score;
}					t_app;


void	ft_init_board_or_piece(t_app *app, char *str);
void	ft_set_player(t_app *app, char *str);
void	ft_set_current_player(t_app *app, char *str);
void	ft_set_board(t_app *app, char *str);
void	ft_set_piece(t_app *app, char *str);
void	ft_set_winner(t_app *app, char *str);

void	ft_clear_list(t_app *app);
void	ft_clean_tab(char **tab);

void	ft_debug_player(t_app *app);
void	ft_debug_board(t_app *app);
void	ft_debug_piece(t_app *app);
void	ft_debug_lst(t_app *app);
void	ft_debug_current_player(t_app *app);

void	ft_nc_init_window(t_app *app);
void	ft_nc_init(t_app *app);
int		ft_nc_update(t_app *app);

#endif