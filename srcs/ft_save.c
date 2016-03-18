#include "filler.h"

void	ft_set_point_right(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	if (player == 1)
		app->pos[0].right = p;
	else
		app->pos[1].right = p;
}

void	ft_set_point_left(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	if (player == 1)
		app->pos[0].left = p;
	else
		app->pos[1].left = p;
}

void	ft_set_point_top(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));

	p.x = x;
	p.y = y;
	if (player == 1)
		app->pos[0].top = p;
	else
		app->pos[1].top = p;
}

void	ft_set_point_bot(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	if (player == 1)
		app->pos[0].bot = p;
	else
		app->pos[1].bot = p;
}

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