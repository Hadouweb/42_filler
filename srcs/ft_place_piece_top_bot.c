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

void	ft_place_piece_left_top(t_app *app)
{
	int		x;
	int		y;

	y = 0;
	while (y < app->board.y)
	{
		x = 0;
		while (x < app->board.x)
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
			if (ft_is_valid_pos(app, y_max, x_max))
			{
				ft_print(y_max, x_max);
				return ;
			}
		}
	}
	app->play = 0;
}

void	ft_place_piece_right_top(t_app *app)
{
	int		x_max;
	int		y;

	y = 0;
	while (y < app->board.y)
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