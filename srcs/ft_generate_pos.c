/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:15:03 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/22 21:15:04 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_valid_pos(t_app *app, int y, int x)
{
	int		px;
	int		py;
	int		star;
	char	c;

	py = 0;
	star = 0;
	while (py < app->piece.y)
	{
		px = 0;
		while (px < app->piece.x)
		{
			if (y + py >= app->board.y || x + px >= app->board.x)
				return (0);
			c = ft_tolower(app->board.tab[y + py][x + px]);
			if (c == app->me && app->piece.tab[py][px] == '*')
				star++;
			if (app->piece.tab[py][px] == '*' && c == app->enemy)
				return (0);
			px++;
		}
		py++;
	}
	if (star != 1)
		return (0);
	return (1);
}

void	ft_calculate_dist(t_app *app)
{
	int		me;
	int		en;

	ft_calculate_edge(app);
	me = app->id_me;
	en = app->id_enemy;
	app->dist[0].value = app->pos[en].left.x - app->pos[me].left.x;
	app->dist[0].id = 1;
	app->dist[1].value = app->pos[me].right.x - app->pos[en].right.x;
	app->dist[1].id = 2;
	app->dist[2].value = app->pos[en].top.y - app->pos[me].top.y;
	app->dist[2].id = 4;
	app->dist[3].value = app->pos[me].bot.y - app->pos[en].bot.y;
	app->dist[3].id = 8;
}

void	ft_init_way(t_app *app)
{
	app->way[0].f = ft_place_piece_left_top;
	app->way[0].token = 0x14;
	app->way[1].f = ft_place_piece_right_top;
	app->way[1].token = 0x24;
	app->way[2].f = ft_place_piece_left_bot;
	app->way[2].token = 0x18;
	app->way[3].f = ft_place_piece_right_bot;
	app->way[3].token = 0x28;
	app->way[4].f = ft_place_piece_top_left;
	app->way[4].token = 0x41;
	app->way[5].f = ft_place_piece_top_right;
	app->way[5].token = 0x42;
	app->way[6].f = ft_place_piece_bot_left;
	app->way[6].token = 0x81;
	app->way[7].f = ft_place_piece_bot_right;
	app->way[7].token = 0x82;
}

void	ft_best_way(t_app *app, unsigned char way)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	while (i < 8)
	{
		if (way == app->way[i].token)
		{
			find = 1;
			break ;
		}
		i++;
	}
	if (!find)
	{
		i = 0;
		while (i < 8)
		{
			if (way & app->way[i].token)
				break ;
			i++;
		}
	}
	app->way[i].f(app);
}


void	ft_sort_way(t_app *app)
{
	int				i;
	t_dist			tmp;
	unsigned char	way;

	i = 0;
	ft_bzero(&tmp, sizeof(t_dist));
	way = 0;
	while (i < 3)
	{
		if (app->dist[i + 1].value < app->dist[i].value)
		{
			tmp = app->dist[i];
			app->dist[i] = app->dist[i + 1];
			app->dist[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	way |= app->dist[0].id;
	way <<= 4;
	way |= app->dist[1].id;
	ft_best_way(app, way);
}

void	ft_generate_pos(t_app *app)
{
	ft_calculate_dist(app);
	ft_sort_way(app);
}
