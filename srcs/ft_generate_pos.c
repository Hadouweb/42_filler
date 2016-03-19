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
				app->block |= 0x01;
			if (ft_tolower(app->board.tab[y][x]) == app->me && x == x_max - 1)
				app->block |= 0x02;
			if (ft_tolower(app->board.tab[y][x]) == app->me && y == 0)
				app->block |= 0x04;
			if (ft_tolower(app->board.tab[y][x]) == app->me && y == y_max - 1)
				app->block |= 0x08;
			x++;
		}
		y++;
	}
}

void	ft_debug_block(t_app *app)
{
	if (app->block & 0x01)
	{
		app->dist[0] = app->dist[1];
		app->dist[2] = app->dist[6];
		app->dist[3] = app->dist[7];
		app->dist[4] = app->dist[5];
	}
	if (app->block & 0x02)
	{
		app->dist[1] = app->dist[0];
		app->dist[5] = app->dist[4];
		app->dist[6] = app->dist[2];
		app->dist[7] = app->dist[3];
	}
	if (app->block & 0x04)
	{
		app->dist[0] = app->dist[4];
		app->dist[1] = app->dist[5];
		app->dist[2] = app->dist[3];
		app->dist[6] = app->dist[7];
	}
	if (app->block & 0x08)
	{
		app->dist[3] = app->dist[2];
		app->dist[4] = app->dist[0];
		app->dist[5] = app->dist[1];
		app->dist[7] = app->dist[6];
	}
}

void	ft_best_way(t_app *app)
{
	int		i;
	t_dist	best;

	i = 0;
	best = app->dist[0];
	if (app->dist[2].value < 0)
		best = app->dist[2];
	else if (app->dist[3].value < 0)
		best = app->dist[3];
	else if (app->dist[0].value < 0)
		best = app->dist[0];
	else if (app->dist[1].value < 0)
		best = app->dist[1];
	best.f(app);
}

void	ft_init_way(t_app *app)
{
	app->dist[0].f = ft_place_piece_top_left;
	app->dist[1].f = ft_place_piece_top_right;
	app->dist[2].f = ft_place_piece_left_top;
	app->dist[3].f = ft_place_piece_left_bot;
	app->dist[4].f = ft_place_piece_bot_left;
	app->dist[5].f = ft_place_piece_bot_right;
	app->dist[6].f = ft_place_piece_right_top;
	app->dist[7].f = ft_place_piece_right_bot;
}

void	ft_generate_pos(t_app *app)
{
	int		me;
	int		en;

	ft_calculate_edge(app);
	me = app->id_me;
	en = app->id_enemy;
	ft_init_way(app);
	app->dist[0].value = app->pos[en].left.x - app->pos[me].left.x;
	app->dist[1].value = app->pos[me].right.x - app->pos[en].right.x;
	app->dist[2].value = app->pos[en].top.y - app->pos[me].top.y;
	app->dist[3].value = app->pos[me].bot.y - app->pos[en].bot.y;
	app->dist[4].value = app->pos[en].left.x - app->pos[me].left.x;
	app->dist[5].value = app->pos[me].right.x - app->pos[en].right.x;
	app->dist[6].value = app->pos[en].top.y - app->pos[me].top.y;
	app->dist[7].value = app->pos[me].bot.y - app->pos[en].bot.y;
	//ft_debug_dist(app);
	ft_verif_block(app);
	ft_debug_block(app);
	ft_best_way(app);
}