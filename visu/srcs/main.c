/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 02:39:17 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/23 02:39:18 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	ft_parsing(t_app *app, char *str)
{
	if (str[0])
	{
		if (str[0] == '$')
			ft_set_player(app, str);
		else if (str[0] == 'P')
			ft_init_board_or_piece(app, str);
		else if (str[0] == '<')
			ft_set_current_player(app, str);
		else if (app->mode == 1)
			ft_set_board(app, str);
		else if (app->mode == 2)
			ft_set_piece(app, str);
		else if (str[0] == '=')
			ft_set_winner(app, str);
	}
}

int			main(void)
{
	char	*line;
	t_app	app;

	line = NULL;
	ft_bzero(&app, sizeof(t_app));
	app.list_tmp = NULL;
	app.speed = 200;
	while (1)
	{
		if (app.render.run || !app.start)
		{
			if (get_next_line(0, &line) > 0)
			{
				if (!app.nc && app.board.x && ++app.nc)
					ft_nc_init(&app);
				ft_parsing(&app, line);
				ft_strdel(&line);
				app.line++;
			}
			else
				break ;
		}
		ft_nc_key_hook(&app);
	}
	return (0);
}
