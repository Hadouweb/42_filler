#include "filler.h"

void	ft_place_piece_top_left(t_app *app)
{
	int		x;
	int		y;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	app->best_x = x_max;
	y = 0;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_is_valid_pos(app, y, x) && x < app->best_x)
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
			if (ft_is_valid_pos(app, y, x_max) && x_max > app->best_x)
			{
				app->best_y = y;
				app->best_x = x_max;
			}
		}
		y++;
	}
	ft_print(app->best_y, app->best_x);
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

void	ft_place_piece_bot_right(t_app *app)
{
	int		x_max;
	int		y_max;

	y_max = app->board.y;
	app->best_y = y_max;
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
