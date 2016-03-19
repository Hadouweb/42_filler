#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

typedef struct 		s_app t_app;

typedef struct 		s_point
{
	int				x;
	int				y;	
}					t_point;

typedef struct 		s_pos
{
	t_point			left;
	t_point			right;
	t_point			top;
	t_point			bot;
}					t_pos;

typedef struct 		s_piece
{
	int				x;
	int				y;
	char			**tab;
	int				current_line;
}					t_piece;

typedef struct 		s_board
{
	int				x;
	int				y;
	char			**tab;
	int				current_line;
}					t_board;

typedef struct 		s_dist
{
	int				value;
	void			(*f)(t_app *);
}					t_dist;

struct 				s_app
{
	char			id_player;
	t_board			board;
	t_piece			piece;
	t_list			*list_tmp;
	int				mode;
	char			me;
	char			enemy;
	int 			id_me;
	int				id_enemy;
	int				id_current_player;
	int				play;
	t_pos			pos[2];
	t_dist			dist[4];
};

void				ft_debug_list(t_list *list);
void				ft_debug_tab_b(t_app *app);
void				ft_debug_tab_p(t_app *app);
void				ft_debug_pos(t_app *app);
void				ft_debug_dist(t_app *app);

void				ft_init_board_or_piece(t_app *app, char *str);

void				ft_set_player(t_app *app, char *str);
void				ft_set_board(t_app *app, char *str);
void				ft_set_piece(t_app *app, char *str);
void				ft_set_current_player(t_app *app, char *str);

void				ft_print(int x, int y);
void				ft_clear_list(t_app *app);
void				ft_clear_tab(char **tab);

void				ft_set_data(t_app *app, char *line);

void				ft_generate_pos(t_app *app);
int					ft_is_valid_pos(t_app *app, int x, int y);
void				ft_calculate_edge(t_app *app);

void				ft_calc_right(t_app *app);
void				ft_calc_left(t_app *app);
void				ft_calc_top(t_app *app);
void				ft_calc_bot(t_app *app);

void				ft_place_piece_left(t_app *app);
void				ft_place_piece_right(t_app *app);
void				ft_place_piece_top(t_app *app);
void				ft_place_piece_bot(t_app *app);

void				ft_set_point_right(int player, t_app *app, int x, int y);
void				ft_set_point_left(int player, t_app *app, int x, int y);
void				ft_set_point_top(int player, t_app *app, int x, int y);
void				ft_set_point_bot(int player, t_app *app, int x, int y);

#endif