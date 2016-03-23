/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece_left_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:15:12 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/22 21:15:14 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_piece_top_left(t_app *app)
{
	int		x;
	int		y;
	int		y_max;
	int		x_max;

	y_max = app->board.y;
	x_max = app->board.x;
	x = 0;
	while (x < x_max)
	{
		y = 0;
		while (y < y_max)
		{
			if (ft_is_valid_pos(app, y, x))
			{
				ft_print(y, x);
				return ;
			}
			y++;
		}
		x++;
	}
	app->play = 0;
}

void	ft_place_piece_top_right(t_app *app)
{
	int		y;
	int		x_max;
	int		y_max;

	y_max = app->board.y;
	x_max = app->board.x;
	while (x_max--)
	{
		y = 0;
		while (y < y_max)
		{
			if (ft_is_valid_pos(app, y, x_max))
			{
				ft_print(y, x_max);
				return ;
			}
			y++;
		}
	}
	app->play = 0;
}

void	ft_place_piece_bot_left(t_app *app)
{
	int		x;
	int		y_max;
	int		x_max;

	x_max = app->board.x;
	x = 0;
	while (x < x_max)
	{
		y_max = app->board.y;
		while (y_max--)
		{
			if (ft_is_valid_pos(app, y_max, x))
			{
				ft_print(y_max, x);
				return ;
			}
		}
		x++;
	}
	app->play = 0;
}

void	ft_place_piece_bot_right(t_app *app)
{
	int		x_max;
	int		y_max;

	x_max = app->board.x;
	while (x_max--)
	{
		y_max = app->board.y;
		while (y_max--)
		{
			if (ft_is_valid_pos(app, y_max, x_max))
			{
				ft_print(y_max, x_max);
				return ;
			}
		}
	}
	app->play = 0;
}
