#include "filler.h"

void	ft_generate_board(t_game *g, t_line *l)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = NULL;
	while (l)
	{
		str = l->str;
		if (*str && str[0] == '0')
		{
			while (*str && *str != ' ')
				str++;
			if (*str)
				str++;
			y = 0;
			while (y < g->board->y && *str)
			{
				g->board->b[x][y] = *str;
				y++;
				str++;
			}
			x++;
		}
		l = l->next;
	}
	ft_debug_tab_b(g);
}

void	ft_generate_piece(t_game *g, t_line *l)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = NULL;
	while (l)
	{
		str = l->str;
		y = 0;
		while (y < g->piece->y && *str)
		{
			g->piece->p[x][y] = *str;
			y++;
			str++;
		}
		x++;
		l = l->next;
	}
	ft_debug_tab_p(g);
}

void	ft_loop(t_game *g, char *line, t_line **lst_b, t_line **lst_p)
{
	if (!ft_check_mode(g, line))
	{
		if (g->mode == 1 && ++g->clb)
		{
			ft_list_push_back(lst_b, line);
			if (g->clb == g->board->x + 1)
			{
				ft_generate_board(g, *lst_b);
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
				ft_generate_piece(g, *lst_p);
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