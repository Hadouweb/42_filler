#include "filler.h"

void	ft_loop(t_game *g, char *line, t_line **lst_b, t_line **lst_p)
{
	if (!ft_check_mode(g, line))
	{
		if (g->mode == 1 && ++g->clb)
		{
			ft_list_push_back(lst_b, line);
			if (g->clb == g->board->x + 1)
			{
				ft_set_board(g, *lst_b);
				//ft_debug_list(*lst_b);
				ft_clear_list(lst_b);
				g->clb = 0;
			}
		}
		if (g->mode == 2 && ++g->clp)
		{
			ft_list_push_back(lst_p, line);
			if (g->clp == g->piece->x)
			{
				ft_set_piece(g, *lst_p);
				//ft_debug_list(*lst_p);
				ft_clear_list(lst_p);
				ft_putstr("0 1\n");
				g->mode = 0;
				g->clp = 0;
			}
		}
	}
}

int		main(void)
{
	char	*line;
	t_game	g;
	int		loop;
	t_line 	*lst_b;
	t_line 	*lst_p;

	loop = 1;
	ft_bzero(&g, sizeof(t_game));
	lst_b = NULL;
	lst_p = NULL;
	while (get_next_line(0, &line) && loop)
	{
		if (!g.id_player)
			ft_set_id_player(&g, line);
		else
			ft_loop(&g, line, &lst_b, &lst_p);
		ft_strdel(&line);
	}
	return (0);
}