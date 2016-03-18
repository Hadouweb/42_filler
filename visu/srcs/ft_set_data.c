#include "visu.h"

void	ft_set_winner(t_app *app, char *str)
{
	if (ft_strlen(str) > 4)
	{
		str += 3;
		if (str[0] == 'O')
			app->p1_score = ft_atoi(str + 7);
		else
		{
			app->p2_score = ft_atoi(str + 7);
			app->is_finish = 1;
		}
	}
}

void	ft_set_player(t_app *app, char *str)
{
	t_player	p;
	int			i;
	int			start;

	if (ft_strlen(str) > 11)
		str += 10;
	p.id = ft_atoi(str);
	i = 0;
	start = 0;
	while (str[i])
	{
		start++;
		if (str[i] == '/')
			start = 0;
		i++;
	}
	str = (&str[i] - start);
	p.name = ft_strndup(str, ft_strlen(str) - 1);
	if (p.id == 1)
		app->p1 = p;
	if (p.id == 2)
		app->p2 = p;
}

void	ft_set_current_player(t_app *app, char *str)
{
	if (ft_strlen(str) > 10)
	{
		str += 6;
		if (str[0] == 'O')
			app->current_player = app->p1;
		else
			app->current_player = app->p2;
		//ft_debug_current_player(app);
		ft_nc_update(app);
		app->start = 1;
	}
}

void	ft_init_board_or_piece(t_app *app, char *str)
{
	if (ft_strstr(str, "Plateau"))
	{
		if (!app->board.x)
		{
			app->board.y = ft_atoi(str += 8);
			app->board.x = ft_atoi(str += 2);
		}
		ft_clean_tab(app->board.tab);
		app->mode = 1;
	}
	else if (ft_strstr(str, "Piece"))
	{
		app->piece.y = ft_atoi(str += 6);
		app->piece.x = ft_atoi(str += 2);
		ft_clean_tab(app->piece.tab);
		app->mode = 2;
	}
}

void	ft_set_board(t_app *app, char *str)
{
	if (ft_strlen(str) >= (size_t)app->board.x)
	{
		str += 4;
		if (app->board.current_line >= 1)
			ft_lstpush_back(&app->list_tmp, str, ft_strlen(str) + 1);
		app->board.current_line++;
		if (app->board.current_line == app->board.y + 1)
		{
			app->board.tab = (char**)ft_lsttotab(app->list_tmp);
			ft_clear_list(app);
			//ft_debug_board(app);
			ft_nc_update(app);
			app->mode = 0;
			app->board.current_line = 0;
		}
	}
}

void	ft_set_piece(t_app *app, char *str)
{
	if (*str)
	{
		ft_lstpush_back(&app->list_tmp, str, ft_strlen(str) + 1);
		app->piece.current_line++;
		if (app->piece.current_line == app->piece.y)
		{
			app->piece.tab = (char**)ft_lsttotab(app->list_tmp);
			ft_clear_list(app);
			//ft_debug_piece(app);
			ft_nc_update(app);
			app->mode = 0;
			app->piece.current_line = 0;
		}
	}
}
