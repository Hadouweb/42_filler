#include "filler.h"

void	ft_place_piece_left(t_app *app)
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

void	ft_place_piece_right(t_app *app)
{
	int		x;
	int		y;
	int		y_max;

	y_max = app->board.y;
	x = app->board.x;
	while (--x)
	{
		y = 0;
		while (y < y_max)
		{
			if (ft_is_valid_pos(app, y, x))
			{
				ft_print(y, x);
				return ;
			}
			y++;
		}
	}
	app->play = 0;
}

void	ft_place_piece_bot(t_app *app)
{
	int		x;
	int		y;

	y = app->board.y;
	while (y--)
	{
		x = app->board.y;
		while (x--)
		{
			if (ft_is_valid_pos(app, y, x))
			{
				ft_print(y, x);
				return ;
			}
		}
	}
	app->play = 0;
}

void	ft_place_piece_top(t_app *app)
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