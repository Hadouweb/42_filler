#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

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
}					t_piece;

typedef struct 		s_board
{
	int				x;
	int				y;
	char			**tab;
}					t_board;

typedef struct 		s_app
{
	char			id_player;
	t_board			board;
	t_piece			piece;
	t_list			*list_tmp;
	int				mode;
	int				current_line_piece;
	int				current_line_board;
	char			me;
	char			enemy;
	int				loop;
	t_pos			pos[2];
}					t_app;

void				ft_debug_list(t_list *list);
void				ft_debug_tab_b(t_app *app);
void				ft_debug_tab_p(t_app *app);

void				ft_init_board(t_app *app, char *str);
void				ft_init_piece(t_app *app, char *str);

t_list				*ft_create_node(char *str);
void				ft_list_push_back(t_list **l, char *str);
void				ft_clear_list(t_list **list);

void				ft_set_id_player(t_app *app, char *str);
void				ft_set_board(t_app *app, t_list *l);
void				ft_set_piece(t_app *app, t_list *l);

int					ft_check_mode(t_app *app, char *str);

void				ft_loop(t_app *app, char *line);
#endif