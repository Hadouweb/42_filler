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

int		ft_is_valid_pos(t_app *app, int x, int y)
{
	int		vx;
	int		vy;
	int		star;

	vx = 0;
	star = 0;
	while (vx < app->piece.x)
	{
		vy = 0;
		while (vy < app->piece.y)
		{
			if (x + vx >= app->board.x || y + vy >= app->board.y)
				return (0);
			if (ft_tolower(app->board.tab[x + vx][y + vy]) == app->me &&
				app->piece.tab[vx][vy] == '*')
			{
				//ft_print_pos(x, y);
				//ft_print_pos(vx, vy);
				star++;
				//if (ft_no_enemy())
			}
			if (app->piece.tab[vx][vy] == '*' &&
				ft_tolower(app->board.tab[x + vx][y + vy]) == app->enemy)
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

void	ft_set_point_right(int player, t_app *app, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		app->pos[0].right = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		app->pos[1].right = p;
	}
}

void	ft_set_point_left(int player, t_app *app, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		app->pos[0].left = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		app->pos[1].left = p;
	}
}

void	ft_set_point_top(int player, t_app *app, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		app->pos[0].top = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		app->pos[1].top = p;
	}
}

void	ft_set_point_bot(int player, t_app *app, int x, int y)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	if (player == 1)
	{
		p.x = x;
		p.y = y;
		app->pos[0].bot = p;
	}
	else
	{
		p.x = x;
		p.y = y;
		app->pos[1].bot = p;
	}
}

void	ft_calc_right(t_app *app)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;

	y = 0;
	x_max = app->board.x;
	y_max = app->board.y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_tolower(app->board.tab[x][y]) == 'x')
				ft_set_point_right(1, app, x, y);
			if (ft_tolower(app->board.tab[x][y]) == 'o')
				ft_set_point_right(2, app, x, y);
			x++;
		}
		y++;
	}
}

void	ft_calc_left(t_app *app)
{
	int		x_max;
	int		y_max;

	x_max = app->board.x;
	y_max = app->board.y;
	while (y_max--)
	{
		x_max = app->board.x;
		while (x_max--)
		{
			if (ft_tolower(app->board.tab[x_max][y_max]) == 'x')
				ft_set_point_left(1, app, x_max, y_max);
			if (ft_tolower(app->board.tab[x_max][y_max]) == 'o')
				ft_set_point_left(2, app, x_max, y_max);
		}
	}
}

void	ft_calc_top(t_app *app)
{
	int		x_max;
	int		y_max;

	x_max = app->board.x;
	y_max = app->board.y;
	while (y_max--)
	{
		x_max = app->board.x;
		while (x_max--)
		{
			if (ft_tolower(app->board.tab[x_max][y_max]) == 'x')
				ft_set_point_top(1, app, x_max, y_max);
			if (ft_tolower(app->board.tab[x_max][y_max]) == 'o')
				ft_set_point_top(2, app, x_max, y_max);
		}
	}
}

void	ft_calc_bot(t_app *app)
{
	int		x_max;
	int		y_max;
	int		x;
	int		y;

	y = 0;
	x_max = app->board.x;
	y_max = app->board.y;
	while (y < y_max)
	{
		x = 0;
		while (x < x_max)
		{
			if (ft_tolower(app->board.tab[x][y]) == 'x')
				ft_set_point_bot(1, app, x, y);
			if (ft_tolower(app->board.tab[x][y]) == 'o')
				ft_set_point_bot(2, app, x, y);
			x++;
		}
		y++;
	}
}

void	ft_place_piece_left(t_app *app)
{
	int		x;
	int		y;

	x = 0;
	while (x < app->board.x)
	{
		y = 0;
		while (y < app->board.y)
		{
			if (ft_is_valid_pos(app, x, y))
			{
				ft_print(x, y);
				return ;
			}
			y++;
		}
		x++;
	}
	app->loop = 0;
}

void	ft_place_piece_right(t_app *app)
{
	int		x;
	int		y;

	x = app->board.x;
	while (x--)
	{
		y = app->board.y;
		while (y--)
		{
			if (ft_is_valid_pos(app, x, y))
			{
				ft_print(x, y);
				return ;
			}
		}
	}
	app->loop = 0;
}

void	ft_place_piece_top(t_app *app)
{
	int		x;
	int		y;

	x = app->board.x;
	while (x--)
	{
		y = app->board.y;
		while (y--)
		{
			if (ft_is_valid_pos(app, x, y))
			{
				ft_print(x, y);
				return ;
			}
		}
	}
	app->loop = 0;
}

void	ft_place_piece_bot(t_app *app)
{
	int		x;
	int		y;

	x = 0;
	while (x < app->board.x)
	{
		y = 0;
		while (y < app->board.y)
		{
			if (ft_is_valid_pos(app, x, y))
			{
				ft_print(x, y);
				return ;
			}
			y++;
		}
		x++;
	}
	app->loop = 0;
}

void	ft_calc_dist(t_app *app)
{
	ft_calc_right(app);
	ft_calc_left(app);
	ft_calc_top(app);
	ft_calc_bot(app);
	if (app->pos[0].left.y - app->pos[1].right.y < 0)
		ft_place_piece_left(app);
	else if (app->pos[0].right.y - app->pos[1].left.y > 0)
		ft_place_piece_right(app);
	else if (app->pos[0].top.y - app->pos[1].bot.y < 0)
		ft_place_piece_bot(app);
	else if (app->pos[0].bot.y - app->pos[1].top.y > 0)
		ft_place_piece_top(app);
	else
		ft_place_piece_bot(app);
	/*fprintf(stderr, "____left - right %d\n", app->pos[0].left.y - app->pos[1].right.y);
	fprintf(stderr, "____right - left %d\n", app->pos[0].right.y - app->pos[1].left.y);
	fprintf(stderr, "____top - bot %d\n", app->pos[0].top.x - app->pos[1].bot.x);
	fprintf(stderr, "____bot - top %d\n", app->pos[0].bot.x - app->pos[1].top.x);
	ft_debug_pos(app);*/
}

void	ft_loop(t_app *app, char *line)
{
	if (!ft_check_mode(app, line))
	{
		if (app->mode == 1 && ++app->current_line_board)
		{
			ft_lstpush_back(&app->list_tmp, line, ft_strlen(line));
			if (app->current_line_board == app->board.x + 1)
			{
				ft_set_board(app, app->list_tmp);
				ft_clear_list(&app->list_tmp);
				app->current_line_board = 0;
				app->mode = 0;
			}
		}
		if (app->mode == 2 && ++app->current_line_piece)
		{
			ft_lstpush_back(&app->list_tmp, line, ft_strlen(line));
			if (app->current_line_piece == app->piece.x)
			{
				ft_set_piece(app, app->list_tmp);
				//ft_debug_tab_p(app);
				ft_calc_dist(app);
				//ft_debug_list(*lst_p);
				ft_clear_list(&app->list_tmp);
				app->current_line_piece = 0;
				app->mode = 0;
			}
		}
	}
}