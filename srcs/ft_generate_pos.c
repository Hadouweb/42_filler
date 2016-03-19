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

void	ft_init_way(t_app *app)
{
	app->dist[0].f = ft_place_piece_left;
	app->dist[1].f = ft_place_piece_right;
	app->dist[2].f = ft_place_piece_top;
	app->dist[3].f = ft_place_piece_bot;
}

void	ft_best_way(t_app *app)
{
	int		i;
	t_dist	best;

	i = 0;
	best = app->dist[0];
	while (i < 4)
	{
		if (app->dist[i].value < best.value)
		{
			best = app->dist[i];
			i = 0;
		}
		else
			i++;
	}
	best.f(app);
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
	//ft_debug_dist(app);
	ft_best_way(app);
}