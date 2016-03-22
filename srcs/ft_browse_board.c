#include "filler.h"

void	ft_calc_left_and_right(t_app *app)
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

			if (c == 'o' && x > app->pos[0].right.x)
				ft_set_point_right(0, app, y, x);
			if (c == 'x' && x > app->pos[0].right.x)
				ft_set_point_right(1, app, y, x);
			if (c == 'o' && x < app->pos[0].left.x)
				ft_set_point_left(0, app, y, x);
			if (c == 'x' && x < app->pos[1].left.x)
				ft_set_point_left(1, app, y, x);
			x++;
		}
		y++;
	}
}

void	ft_calc_top_and_bot(t_app *app)
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

			if (c == 'o' && y > app->pos[0].bot.y)
				ft_set_point_bot(0, app, y, x);
			if (c == 'x' && y > app->pos[1].bot.y)
				ft_set_point_bot(1, app, y, x);

			if (c == 'o' && y < app->pos[0].top.y)
				ft_set_point_top(0, app, y, x);
			if (c == 'x' && y < app->pos[1].top.y)
				ft_set_point_top(1, app, y, x);
			x++;
		}
		y++;
	}
}

void	ft_init_pos(t_app *app)
{
	app->pos[0].left.x = app->board.x;
	app->pos[1].left.x = app->board.x;
	app->pos[0].top.y = app->board.y;
	app->pos[1].top.y = app->board.y;
}

void	ft_calculate_edge(t_app *app)
{
	ft_init_pos(app);
	ft_calc_left_and_right(app);
	ft_calc_top_and_bot(app);
}
