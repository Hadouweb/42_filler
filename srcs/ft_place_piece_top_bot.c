#include "filler.h"

void	ft_place_piece_left_bot(t_app *app)
{
	int		x;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	while (--y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_is_valid_pos(app, y_max, x) && y_max > app->best_y)
			{
				app->best_y = y_max;
				app->best_x = x;
			}
			x++;
		}
	}
	ft_print(app->best_y, app->best_x);
}

void	ft_place_piece_left_top(t_app *app)
{
	int		x;
	int		y;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	y = 0;
	app->best_y = y_max;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_is_valid_pos(app, y, x) && y < app->best_y)
			{
				app->best_y = y;
				app->best_x = x;
			}
			x++;
		}
		y++;
	}
	ft_print(app->best_y, app->best_x);
}

void	ft_place_piece_right_bot(t_app *app)
{
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	while (--y_max)
	{
		x_max = app->board.x;
		while (--x_max)
		{
			if (ft_is_valid_pos(app, y_max, x_max) && y_max > app->best_y)
			{
				app->best_y = y_max;
				app->best_x = x_max;
			}
		}
	}
	ft_print(app->best_y, app->best_x);
}

void	ft_place_piece_right_top(t_app *app)
{
	int		x_max;
	int		y_max;
	int		y;

	y = 0;
	y_max = app->board.y;
	app->best_y = y_max;
	while (y < app->board.y)
	{
		x_max = app->board.x;
		while (--x_max)
		{
			if (ft_is_valid_pos(app, y, x_max) && y < app->best_y)
			{
				app->best_y = y;
				app->best_x = x_max;
			}
		}
		y++;
	}
	ft_print(app->best_y, app->best_x);
}
