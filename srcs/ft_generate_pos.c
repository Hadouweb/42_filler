#include "filler.h"

int		ft_is_valid_pos(t_app *app, int y, int x)
{
	int		px;
	int		py;
	int		star;

	py = 0;
	star = 0;
	//fprintf(stderr, "___%d %d\n", y, x);
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

void	ft_generate_pos(t_app *app)
{
	ft_calculate_edge(app);
	if (app->pos[0].left.x - app->pos[1].right.x < 0)
		ft_place_piece_left(app);
	else if (app->pos[0].right.x - app->pos[1].left.x > 0)
		ft_place_piece_right(app);
	else if (app->pos[0].top.y - app->pos[1].bot.y > 0)
		ft_place_piece_bot(app);
	else if (app->pos[0].bot.y - app->pos[1].top.y < 0)
		ft_place_piece_top(app);
	else
		ft_place_piece_bot(app);
}