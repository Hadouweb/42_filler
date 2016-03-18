#include "filler.h"

void	ft_debug_list(t_list *list)
{
	while (list)
	{
		fprintf(stderr, "_____________________%s\n", list->content);
		list = list->next;
	}
	fprintf(stderr, "||||||||||||||||||||||||||||\n");
}

void	ft_debug_tab_b(t_app *app)
{
	int		x;

	x = 0;
	usleep(10000);
	ft_putstr_fd("______________________\n", 2);
	while (x < app->board.x)
	{
		ft_putstr_fd(app->board.tab[x], 2);
		ft_putstr_fd("\n", 2);
		x++;
	}
	ft_putstr_fd("______________________\n", 2);
	usleep(10000);
}

void	ft_debug_tab_p(t_app *app)
{
	int		x;

	x = 0;
	usleep(10000);
	ft_putstr_fd("______________________\n", 2);
	while (x < app->piece.x)
	{
		ft_putstr_fd(app->piece.tab[x], 2);
		ft_putstr_fd("\n", 2);
		x++;
	}
	ft_putstr_fd("______________________\n", 2);
	usleep(10000);
}

void	ft_debug_pos(t_app *app)
{
	fprintf(stderr, "________p1 right : %d %d\n", app->pos[0].right.x, app->pos[0].right.y);
	fprintf(stderr, "________p1 left : %d %d\n", app->pos[0].left.x, app->pos[0].left.y);
	fprintf(stderr, "________p1 top : %d %d\n", app->pos[0].top.x, app->pos[0].top.y);
	fprintf(stderr, "________p1 bot : %d %d\n", app->pos[0].bot.x, app->pos[0].bot.y);
	fprintf(stderr, "________p2 right : %d %d\n", app->pos[1].right.x, app->pos[1].right.y);
	fprintf(stderr, "________p2 left : %d %d\n", app->pos[1].left.x, app->pos[1].left.y);
	fprintf(stderr, "________p2 top : %d %d\n", app->pos[1].top.x, app->pos[1].top.y);
	fprintf(stderr, "________p2 bot : %d %d\n", app->pos[1].bot.x, app->pos[1].bot.y);
}

void	ft_print_pos(int x, int y)
{
	ft_putstr_fd("__________________", 2);
	ft_putnbr_fd(x, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(y, 2);
	ft_putstr_fd("\n", 2);
}
