#include "filler.h"

void	ft_debug_list(t_line *list)
{
	while (list)
	{
		fprintf(stderr, "_____________________%s\n", list->str);
		list = list->next;
	}
	fprintf(stderr, "||||||||||||||||||||||||||||\n");
}

void	ft_debug_tab_b(t_game *g)
{
	int		x;

	x = 0;
	usleep(10000);
	ft_putstr_fd("______________________\n", 2);
	while (x < g->board->x)
	{
		ft_putstr_fd(g->board->b[x], 2);
		ft_putstr_fd("\n", 2);
		x++;
	}
	ft_putstr_fd("______________________\n", 2);
	usleep(10000);
}

void	ft_debug_tab_p(t_game *g)
{
	int		x;

	x = 0;
	usleep(10000);
	ft_putstr_fd("______________________\n", 2);
	while (x < g->piece->x)
	{
		ft_putstr_fd(g->piece->p[x], 2);
		ft_putstr_fd("\n", 2);
		x++;
	}
	ft_putstr_fd("______________________\n", 2);
	usleep(10000);
}
