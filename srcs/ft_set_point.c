#include "filler.h"

void	ft_set_point_right(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].right = p;
}

void	ft_set_point_left(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].left = p;
}

void	ft_set_point_top(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].top = p;
}

void	ft_set_point_bot(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].bot = p;
}
