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
	int		y;

	x = 0;
	fprintf(stderr, "\n_________________________\n");
	while (x < g->board->x)
	{
		y = 0;
		while (y < g->board->y)
		{
			fprintf(stderr, "%c", g->board->b[x][y]);
			y++;
		}
		fprintf(stderr, "\n");
		x++;
	}
	fprintf(stderr, "\n_________________________\n");
}

void	ft_debug_tab_p(t_game *g)
{
	int		x;
	int		y;

	x = 0;
	fprintf(stderr, "\n_________________________\n");
	while (x < g->piece->x)
	{
		y = 0;
		while (y < g->piece->y)
		{
			fprintf(stderr, "%c", g->piece->p[x][y]);
			y++;
		}
		fprintf(stderr, "\n");
		x++;
	}
	fprintf(stderr, "\n_________________________\n");
}
