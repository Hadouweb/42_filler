
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

void	ft_place_piece_left(t_game *g)
{
	int		x;
	int		y;

	x = 0;
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

void	ft_place_piece_right(t_game *g)
{
	int		x;
	int		y;

	x = g->board->x;
	while (x--)
	{
		y = g->board->y;
		while (y--)
		{
			if (ft_is_valid_pos(g, x, y))
			{
				ft_print(x, y);
				return ;
			}
		}
	}
	g->loop = 0;
}

void	ft_place_piece_top(t_game *g)
{
	int		x;
	int		y;

	x = g->board->x;
	while (x--)
	{
		y = g->board->y;
		while (y--)
		{
			if (ft_is_valid_pos(g, x, y))
			{
				ft_print(x, y);
				return ;
			}
		}
	}
	g->loop = 0;
}

void	ft_place_piece_bot(t_game *g)
{
	int		x;
	int		y;

	x = 0;
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

void	ft_calc_dist(t_game *g)
{
	ft_calc_right(g);
	ft_calc_left(g);
	ft_calc_top(g);
	ft_calc_bot(g);
	if (g->pos[0].left.y - g->pos[1].right.y < 0)
		ft_place_piece_left(g);
	else if (g->pos[0].right.y - g->pos[1].left.y > 0)
		ft_place_piece_right(g);
	else if (g->pos[0].top.y - g->pos[1].bot.y < 0)
		ft_place_piece_bot(g);
	else if (g->pos[0].bot.y - g->pos[1].top.y > 0)
		ft_place_piece_top(g);
	else
		ft_place_piece_bot(g);
	/*fprintf(stderr, "____left - right %d\n", g->pos[0].left.y - g->pos[1].right.y);
	fprintf(stderr, "____right - left %d\n", g->pos[0].right.y - g->pos[1].left.y);
	fprintf(stderr, "____top - bot %d\n", g->pos[0].top.x - g->pos[1].bot.x);
	fprintf(stderr, "____bot - top %d\n", g->pos[0].bot.x - g->pos[1].top.x);
	ft_debug_pos(g);*/
}