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
