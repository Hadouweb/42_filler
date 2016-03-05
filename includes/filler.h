#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>

typedef struct 		s_line
{
	char			*str;
	struct s_line	*next;
}					t_line;

typedef struct 		s_piece
{
	int				x;
	int				y;
	char			**p;
}					t_piece;

typedef struct 		s_board
{
	int				x;
	int				y;
	char			**b;
}					t_board;

typedef struct 		s_game
{
	char			id_player;
	t_board			*board;
	t_piece			*piece;
	int				mode;
	int				clp;
	int				clb;
}					t_game;

void				ft_debug_list(t_line *list);
void				ft_debug_tab_b(t_game *g);
void				ft_debug_tab_p(t_game *g);

void				ft_init_board(t_game *g, char *str);
void				ft_init_piece(t_game *g, char *str);

t_line				*ft_create_node(char *str);
void				ft_list_push_back(t_line **l, char *str);
void				ft_clear_list(t_line **list);

void				ft_set_id_player(t_game *g, char *str);
void				ft_set_board(t_game *g, t_line *l);
void				ft_set_piece(t_game *g, t_line *l);

int					ft_check_mode(t_game *g, char *str);
#endif