/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:15:29 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/22 21:15:31 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_set_point_right(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].right = p;
}

void	ft_set_point_left(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].left = p;
}

void	ft_set_point_top(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].top = p;
}

void	ft_set_point_bot(int player, t_app *app, int y, int x)
{
	t_point	p;

	bzero(&p, sizeof(t_point));
	p.x = x;
	p.y = y;
	app->pos[player].bot = p;
}
