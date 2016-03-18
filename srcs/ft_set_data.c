#include "filler.h"

void	ft_set_id_player(t_app *app, char *str)
{
	int		i;

	i = 0;
	if (str[0] && str[0] == '$' && ft_strstr(str, "/filler]"))
	{
		if (ft_strlen(str) >= 12)
			str += 10;
		app->id_player = str[0];
		if (app->id_player == '1')
		{
			app->me = 'o';
			app->enemy = 'x';
		}
		else
		{
			app->me = 'x';
			app->enemy = 'o';
		}
	}
}

void	ft_set_board(t_app *app, t_list *l)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = NULL;
	while (l)
	{
		str = l->content;
		if (*str && str[0] == '0')
		{
			while (*str && *str != ' ')
				str++;
			if (*str)
				str++;
			y = 0;
			while (y < app->board.y && *str)
			{
				app->board.tab[x][y] = *str;
				y++;
				str++;
			}
			x++;
		}
		l = l->next;
	}
	//ft_debug_tab_b(g);
}

void	ft_set_piece(t_app *app, t_list *l)
{
	int		x;
	int		y;
	int		i;
	char	*str;

	x = 0;
	str = NULL;
	while (l)
	{
		str = l->content;
		y = 0;
		i = 0;
		while (y < app->piece.y && str[i])
		{
			app->piece.tab[x][y] = str[i];
			y++;
			i++;
		}
		app->piece.tab[x][y] = '\0';
		x++;
		l = l->next;
	}
	//ft_debug_tab_p(g);
}
