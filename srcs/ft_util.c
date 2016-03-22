/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 21:15:34 by nle-bret          #+#    #+#             */
/*   Updated: 2016/03/22 21:15:35 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print(int y, int x)
{
	char	*str_y;
	char	*str_x;

	str_y = ft_itoa(y);
	str_x = ft_itoa(x);
	write(1, str_y, ft_strlen(str_y));
	write(1, " ", 1);
	write(1, str_x, ft_strlen(str_x));
	write(1, "\n", 1);
}

void	ft_clear_list(t_app *app)
{
	t_list	*l;
	t_list	*tmp;

	l = app->list_tmp;
	tmp = NULL;
	while (l)
	{
		free(l->content);
		l->content = NULL;
		l->content_size = 0;
		tmp = l;
		free(l);
		l = tmp->next;
	}
	app->list_tmp = NULL;
}

void	ft_clear_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab && tab[0])
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

int		ft_is_valid_pos(t_app *app, int y, int x, int star)
{
	int		px;
	int		py;
	char	c;

	py = 0;
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
