#include "filler.h"

/*void	ft_reset_tab(t_app *app)
{
	int		y_max;
	int		x_max;
	int		y;
	int		x;

	y_max = app->board.y;
	x_max = app->board.x;
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			app->board.tab[y][x] = app->board.tmp_tab[y][x];
			x++;
		}
		y++;
	}
}

void	ft_get_best_way(t_app *app, int y, int x)
{
	int		y_max;
	int		x_max;
	int		px;
	int		py;
	int		diff_tmp;

	y_max = app->piece.y;
	x_max = app->piece.x;
	py = 0;
	diff_tmp = app->diff_dist;
	while (py < y_max)
	{
		px = 0;
		while (px < x_max)
		{
			if (app->piece.tab[py][px] == '*')
				app->board.tab[py + y][px + x] = app->me;
			px++;
		}
		py++;
	}
//	fprintf(stderr, "_________ diff_dist %d\n", app->diff_dist);
	ft_calculate_dist(app);
	if (app->diff_dist > diff_tmp || !app->find)
	{
//		fprintf(stderr, "_________ FIND %d %d\n", y, x);
		app->best_y = y;
		app->best_x = x;
		app->find = 1;
	}
//	fprintf(stderr, "_________ diff_dist %d\n\n", app->diff_dist);
	//ft_debug_dist(app);
	//ft_debug_tab_b(app);
	ft_reset_tab(app);
}*/

void	ft_place_piece_top_left(t_app *app)
{
	int		x;
	int		y;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_is_valid_pos(app, y, x))
			{
				ft_print(y, x);
				return ;
			}
			x++;
		}
		y++;
	}
	app->play = 0;
}

void	ft_place_piece_top_right(t_app *app)
{
	int		y;
	int		x_max;
	int		y_max;

	y_max = app->board.y;
	y = 0;
	while (y < y_max)
	{
		x_max = app->board.x;
		while (--x_max)
		{
			if (ft_is_valid_pos(app, y, x_max))
			{
				ft_print(y, x_max);
				return ;
			}
		}
		y++;
	}
	app->play = 0;
}

void	ft_place_piece_bot_left(t_app *app)
{
	int		x;
	int		y_max;

	y_max = app->board.y;
	while (--y_max)
	{
		x = 0;
		while (x < app->board.x)
		{
			if (ft_is_valid_pos(app, y_max, x))
			{
				ft_print(y_max, x);
				return ;
			}
			x++;
		}
	}
	app->play = 0;
}

void	ft_place_piece_bot_right(t_app *app)
{
	int		x_max;
	int		y_max;

	y_max = app->board.y;
	while (--y_max)
	{
		x_max = app->board.x;
		while (--x_max)
		{
			if (ft_is_valid_pos(app, y_max, x_max))
			{
				ft_print(y_max, x_max);
				return ;
			}
		}
	}
	app->play = 0;
}
