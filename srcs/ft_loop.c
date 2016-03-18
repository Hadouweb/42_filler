#include "filler.h"

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

void	ft_print_pos(int x, int y)
{
	ft_putstr_fd("__________________", 2);
	ft_putnbr_fd(x, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(y, 2);
	ft_putstr_fd("\n", 2);
}

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
			if (x + vx >= g->board->x || y + vy >= g->board->y)
				return (0);
			if (ft_tolower(g->board->b[x + vx][y + vy]) == g->me &&
				g->piece->p[vx][vy] == '*')
			{
				//ft_print_pos(x, y);
				//ft_print_pos(vx, vy);
				star++;
				//if (ft_no_enemy())
			}
			if (g->piece->p[vx][vy] == '*' &&
				ft_tolower(g->board->b[x + vx][y + vy]) == g->enemy)
				return (0);
			vy++;
		}
		vx++;
	}
	//ft_print_pos(x, y);
	//ft_print_pos(vx, vy);
	if (star != 1)
		return (0);
	return (1);
}

void	ft_debug_pos(t_game *g)
{
	fprintf(stderr, "________p1 right : %d %d\n", g->pos[0].right.x, g->pos[0].right.y);
	fprintf(stderr, "________p1 left : %d %d\n", g->pos[0].left.x, g->pos[0].left.y);
	fprintf(stderr, "________p1 top : %d %d\n", g->pos[0].top.x, g->pos[0].top.y);
	fprintf(stderr, "________p1 bot : %d %d\n", g->pos[0].bot.x, g->pos[0].bot.y);
	fprintf(stderr, "________p2 right : %d %d\n", g->pos[1].right.x, g->pos[1].right.y);
	fprintf(stderr, "________p2 left : %d %d\n", g->pos[1].left.x, g->pos[1].left.y);
	fprintf(stderr, "________p2 top : %d %d\n", g->pos[1].top.x, g->pos[1].top.y);
	fprintf(stderr, "________p2 bot : %d %d\n", g->pos[1].bot.x, g->pos[1].bot.y);
}

void	ft_set_point_right(int player, t_game *g, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		g->pos[0].right = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		g->pos[1].right = p;
	}
}

void	ft_set_point_left(int player, t_game *g, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		g->pos[0].left = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		g->pos[1].left = p;
	}
}

void	ft_set_point_top(int player, t_game *g, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		g->pos[0].top = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		g->pos[1].top = p;
	}
}

void	ft_set_point_bot(int player, t_game *g, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		g->pos[0].bot = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		g->pos[1].bot = p;
	}
}

void	ft_calc_right(t_game *g)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;

	y = 0;
	x_max = g->board->x;
	y_max = g->board->y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_tolower(g->board->b[x][y]) == 'x')
				ft_set_point_right(1, g, x, y);
			if (ft_tolower(g->board->b[x][y]) == 'o')
				ft_set_point_right(2, g, x, y);
			x++;
		}
		y++;
	}
}

void	ft_calc_left(t_game *g)
{
	int		x_max;
	int		y_max;

	x_max = g->board->x;
	y_max = g->board->y;
	while (y_max--)
	{
		x_max = g->board->x;
		while (x_max--)
		{
			if (ft_tolower(g->board->b[x_max][y_max]) == 'x')
				ft_set_point_left(1, g, x_max, y_max);
			if (ft_tolower(g->board->b[x_max][y_max]) == 'o')
				ft_set_point_left(2, g, x_max, y_max);
		}
	}
}

void	ft_calc_top(t_game *g)
{
	int		x_max;
	int		y_max;

	x_max = g->board->x;
	y_max = g->board->y;
	while (y_max--)
	{
		x_max = g->board->x;
		while (x_max--)
		{
			if (ft_tolower(g->board->b[x_max][y_max]) == 'x')
				ft_set_point_top(1, g, x_max, y_max);
			if (ft_tolower(g->board->b[x_max][y_max]) == 'o')
				ft_set_point_top(2, g, x_max, y_max);
		}
	}
}

void	ft_calc_bot(t_game *g)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;

	y = 0;
	x_max = g->board->x;
	y_max = g->board->y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_tolower(g->board->b[x][y]) == 'x')
				ft_set_point_bot(1, g, x, y);
			if (ft_tolower(g->board->b[x][y]) == 'o')
				ft_set_point_bot(2, g, x, y);
			x++;
		}
		y++;
	}
}

void	ft_calc_dist(t_game *g)
{
	ft_calc_right(g);
	ft_calc_left(g);
	ft_calc_top(g);
	ft_calc_bot(g);
	ft_debug_pos(g);
}

void	ft_place_piece(t_game *g)
{
	int		x;
	int		y;

	x = 0;
	ft_calc_dist(g);
	while (x < g->board->x)
	{
		y = 0;
		while (y < g->board->y)
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
				//ft_debug_tab_p(g);
				ft_place_piece(g);
				//ft_debug_list(*lst_p);
				ft_clear_list(lst_p);
				g->mode = 0;
				g->clp = 0;
			}
		}
	}
}