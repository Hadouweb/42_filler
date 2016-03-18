#include "filler.h"

void	ft_set_id_player(t_app *app, char *str)
{
	int		i;

	i = 0;
	if (str[0] && str[0] == '$' && ft_strstr(str, "/filler]"))
	{
		if (ft_strlen(str) >= 12)
			str += 10;
		app->id_player = str[0];
		if (app->id_player == '1')
		{
			app->me = 'o';
			app->enemy = 'x';
		}
		else
		{
			app->me = 'x';
			app->enemy = 'o';
		}
	}
}

void	ft_set_data(t_app *app, char *line)
{
	if (!ft_check_mode(app, line))
	{
		if (app->mode == 1 && ++app->current_line_board)
		{
			if (app->current_line_board > 1)
				ft_lstpush_back(&app->list_tmp, line, ft_strlen(line));
			if (app->current_line_board == app->board.x + 1)
			{
				app->board.tab = (char**)ft_lsttotab(app->list_tmp);
				ft_clear_list(&app->list_tmp);
				app->current_line_board = 0;
				app->mode = 0;
			}
		}
		else if (app->mode == 2 && ++app->current_line_piece)
		{
			ft_lstpush_back(&app->list_tmp, line, ft_strlen(line));
			if (app->current_line_piece == app->piece.x)
			{
				app->piece.tab = (char**)ft_lsttotab(app->list_tmp);
				ft_generate_pos(app);
				ft_clear_list(&app->list_tmp);
				app->current_line_piece = 0;
				app->mode = 0;
			}
		}
	}
}
