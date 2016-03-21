#include "filler.h"

int		ft_is_valid_pos(t_app *app, int y, int x)
{
	int		px;
	int		py;
	int		star;

	py = 0;
	star = 0;
	while (py < app->piece.y)
	{
		px = 0;
		while (px < app->piece.x)
		{
			if (y + py >= app->board.y || x + px >= app->board.x)
				return (0);
			if (ft_tolower(app->board.tab[y + py][x + px]) == app->me &&
				app->piece.tab[py][px] == '*')
				star++;
			if (app->piece.tab[py][px] == '*' &&
				ft_tolower(app->board.tab[y + py][x + px]) == app->enemy)
				return (0);
			px++;
		}
		py++;
	}
	if (star != 1)
		return (0);
	return (1);
}

void	ft_calculate_dist(t_app *app)
{
	int		me;
	int		en;

	ft_calculate_edge(app);
	me = app->id_me;
	en = app->id_enemy;
	app->dist[0].value = app->pos[en].left.x - app->pos[me].left.x;
	app->dist[0].id = 0;
	app->dist[1].value = app->pos[me].right.x - app->pos[en].right.x;
	app->dist[1].id = 1;
	app->dist[2].value = app->pos[en].top.y - app->pos[me].top.y;
	app->dist[2].id = 2;
	app->dist[3].value = app->pos[me].bot.y - app->pos[en].bot.y;
	app->dist[3].id = 3;
}

void	ft_init_way(t_app *app)
{
	app->f[0] = ft_place_piece_left_top;
	app->f[1] = ft_place_piece_right_top;
	app->f[2] = ft_place_piece_top_left;
	app->f[3] = ft_place_piece_top_right;
	app->f[4] = ft_place_piece_left_bot;
	app->f[5] = ft_place_piece_right_bot;
	app->f[6] = ft_place_piece_bot_left;
	app->f[7] = ft_place_piece_bot_right;
}

void	ft_best_way(t_app *app)
{
	if (app->dist[0].id == 0)
	{
		if (app->dist[1].id == 2)
			app->f[0](app);
		else
			app->f[4](app);
	}
	else if (app->dist[0].id == 1)
	{
		if (app->dist[1].id == 2)
			app->f[1](app);
		else
			app->f[5](app);
	}
	else if (app->dist[0].id == 2)
	{
		if (app->dist[1].id == 0)
			app->f[2](app);
		else
			app->f[3](app);
	}
	else if (app->dist[0].id == 3)
	{
		if (app->dist[1].id == 0)
			app->f[6](app);
		else
			app->f[7](app);
	}
}


void	ft_sort_way(t_app *app)
{
	int			i;
	t_dist		tmp;

	i = 0;
	ft_bzero(&tmp, sizeof(t_dist));
	while (i < 4)
	{
		if (app->dist[i + 1].value < app->dist[i].value)
		{
			tmp = app->dist[i];
			app->dist[i] = app->dist[i + 1];
			app->dist[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_verif_block(t_app *app)
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;

	y = 0;
	y_max = app->board.y;
	x_max = app->board.x;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_tolower(app->board.tab[y][x]) == app->me && x == 0)
				app->dist[0] = app->dist[1];
			if (ft_tolower(app->board.tab[y][x]) == app->me && x == x_max - 1)
				app->dist[1] = app->dist[0];
			if (ft_tolower(app->board.tab[y][x]) == app->me && y == 0)
				app->dist[2] = app->dist[3];
			if (ft_tolower(app->board.tab[y][x]) == app->me && y == y_max - 1)
				app->dist[3] = app->dist[2];
			x++;
		}
		y++;
	}
}

void	ft_generate_pos(t_app *app)
{
	app->best_y = 0;
	app->best_x = 0;
	ft_init_way(app);
	ft_calculate_dist(app);
	//ft_debug_dist(app);
	//ft_verif_block(app);
	//ft_debug_block(app);
	ft_sort_way(app);
	ft_best_way(app);
}