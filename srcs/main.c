#include "filler.h"

int		ft_is_valid_pos(t_game *g, int x, int y)
{
	int		vx;
	int		vy;
	int		star;

	vx = 0;
	star = 0;
	while (vx < g->piece->x)
	{
		vy = 0;
		while (vy < g->piece->y)
		{
			if (ft_tolower(g->board->b[x][y]) == g->me)
				star++;
			if (ft_tolower(g->board->b[x][y]) == g->enemy)
				return (0);
			vy++;
			y++;
		}
		vx++;
		x++;
	}
	if (star != 1)
		return (0);
	return (1);
}

void	ft_print(int x, int y)
{
	char	*str_x;
	char	*str_y;

	str_x = ft_itoa(x);
	str_y = ft_itoa(y);
	write(1, str_x, ft_strlen(str_x));
	write(1, " ", 1);
	write(1, str_y, ft_strlen(str_y));
	write(1, "\n", 1);
}

void	ft_place_piece(t_game *g)
{
	int		x;
	int		y;

	x = 0;
	while (x < g->board->x - 1)
	{
		y = 0;
		while (y < g->board->y - 1)
		{
			if (ft_is_valid_pos(g, x, y))
			{
				ft_print(x, y);
				return ;
			}
			y++;
		}
		x++;
	}
	g->loop = 0;
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
				ft_place_piece(g);
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
	t_line 	*lst_b;
	t_line 	*lst_p;

	ft_bzero(&g, sizeof(t_game));
	lst_b = NULL;
	lst_p = NULL;
	g.loop = 1;
	while (get_next_line(0, &line) && g.loop)
	{
		if (!g.id_player)
			ft_set_id_player(&g, line);
		else
			ft_loop(&g, line, &lst_b, &lst_p);
		ft_strdel(&line);
	}
	return (0);
}