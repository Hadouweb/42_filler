#include "filler.h"

int		ft_is_valid_pos(t_app *app, int x, int y)
{
	int		vx;
	int		vy;
	int		star;

	vy = 0;
	star = 0;
	while (vy < app->piece.y)
	{
		vx = 0;
		while (vx < app->piece.x)
		{
			if (y + vy >= app->board.y || x + vx >= app->board.x)
				return (0);
			if (ft_tolower(app->board.tab[y + vy][x + vx]) == app->me &&
				app->piece.tab[vy][vx] == '*')
				star++;
			if (app->piece.tab[vy][vx] == '*' &&
				ft_tolower(app->board.tab[y + vy][x + vx]) == app->enemy)
				return (0);
			vx++;
		}
		vy++;
	}
	if (star != 1)
		return (0);
	return (1);
}

void	ft_generate_pos(t_app *app)
{
	ft_calculate_edge(app);
	if (app->pos[0].left.y - app->pos[1].right.y < 0)
		ft_place_piece_left(app);
	else if (app->pos[0].right.y - app->pos[1].left.y > 0)
		ft_place_piece_right(app);
	else if (app->pos[0].top.y - app->pos[1].bot.y < 0)
		ft_place_piece_bot(app);
	else if (app->pos[0].bot.y - app->pos[1].top.y > 0)
		ft_place_piece_top(app);
	else
		ft_place_piece_bot(app);
}