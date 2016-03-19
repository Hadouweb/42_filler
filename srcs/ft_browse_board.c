#include "filler.h"

void	ft_calc_right(t_app *app)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;
	char	c;

	y = 0;
	x_max = app->board.x;
	y_max = app->board.y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			c = ft_tolower(app->board.tab[y][x]);
			if (c == 'x' && app->pos[0].right.x < x)
				ft_set_point_right(0, app, y, x);
			if (c == 'o' && app->pos[1].right.x < x)
				ft_set_point_right(1, app, y, x);
			x++;
		}
		y++;
	}
}

void	ft_calc_left(t_app *app)
{
	int		x_max;
	int		y_max;

	x_max = app->board.x;
	y_max = app->board.y;
	while (y_max--)
	{
		x_max = app->board.x;
		while (x_max--)
		{
			if (ft_tolower(app->board.tab[y_max][x_max]) == 'x')
				ft_set_point_left(0, app, y_max, x_max);
			if (ft_tolower(app->board.tab[y_max][x_max]) == 'o')
				ft_set_point_left(1, app, y_max, x_max);
		}
	}
}

void	ft_calc_top(t_app *app)
{
	int		x_max;
	int		y_max;

	x_max = app->board.x;
	y_max = app->board.y;
	while (y_max--)
	{
		x_max = app->board.x;
		while (x_max--)
		{
			if (ft_tolower(app->board.tab[y_max][x_max]) == 'x')
				ft_set_point_top(0, app, y_max, x_max);
			if (ft_tolower(app->board.tab[y_max][x_max]) == 'o')
				ft_set_point_top(1, app, y_max, x_max);
		}
	}
}

void	ft_calc_bot(t_app *app)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;

	y = 0;
	x_max = app->board.x;
	y_max = app->board.y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_tolower(app->board.tab[y][x]) == 'x')
				ft_set_point_bot(0, app, y, x);
			if (ft_tolower(app->board.tab[y][x]) == 'o')
				ft_set_point_bot(1, app, y, x);
			x++;
		}
		y++;
	}
}

void	ft_calculate_edge(t_app *app)
{
	ft_calc_right(app);
	ft_calc_left(app);
	ft_calc_top(app);
	ft_calc_bot(app);
	//ft_debug_pos(app);
}
