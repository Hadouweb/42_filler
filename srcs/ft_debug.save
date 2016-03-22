/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:14:56 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/22 21:14:58 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		y;

	y = 0;
	usleep(10000);
	ft_putstr_fd("______________________\n", 2);
	while (y < app->board.y)
	{
		ft_putstr_fd(app->board.tab[y], 2);
		ft_putstr_fd("\n", 2);
		y++;
	}
	ft_putstr_fd("______________________\n", 2);
	usleep(10000);
}

void	ft_debug_tab_p(t_app *app)
{
	int		y;

	y = 0;
	usleep(10000);
	ft_putstr_fd("______________________\n", 2);
	while (y < app->piece.y)
	{
		ft_putstr_fd(app->piece.tab[y], 2);
		ft_putstr_fd("\n", 2);
		y++;
	}
	ft_putstr_fd("______________________\n", 2);
	usleep(10000);
}

void	ft_debug_pos(t_app *app)
{
	fprintf(stderr, "________p1 right : %d %d\n", app->pos[0].right.y, app->pos[0].right.x);
	fprintf(stderr, "________p1 left : %d %d\n", app->pos[0].left.y, app->pos[0].left.x);
	fprintf(stderr, "________p1 top : %d %d\n", app->pos[0].top.y, app->pos[0].top.x);
	fprintf(stderr, "________p1 bot : %d %d\n", app->pos[0].bot.y, app->pos[0].bot.x);
	fprintf(stderr, "________p2 right : %d %d\n", app->pos[1].right.y, app->pos[1].right.x);
	fprintf(stderr, "________p2 left : %d %d\n", app->pos[1].left.y, app->pos[1].left.x);
	fprintf(stderr, "________p2 top : %d %d\n", app->pos[1].top.y, app->pos[1].top.x);
	fprintf(stderr, "________p2 bot : %d %d\n", app->pos[1].bot.y, app->pos[1].bot.x);
}

void	ft_print_pos(int x, int y)
{
	ft_putstr_fd("__________________", 2);
	ft_putnbr_fd(x, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(y, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_debug_dist(t_app *app)
{
	fprintf(stderr, "______ left  : %d\n", app->dist[0].value);
	fprintf(stderr, "______ right : %d\n", app->dist[1].value);
	fprintf(stderr, "______ top   : %d\n", app->dist[2].value);
	fprintf(stderr, "______ bot   : %d\n", app->dist[3].value);
}
