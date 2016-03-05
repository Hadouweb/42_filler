#include "filler.h"

void	ft_set_id_player(t_game *g, char *str)
{
	int		i;

	i = 0;
	if (str[0] && str[0] == '$' && ft_strstr(str, "/filler]"))
	{
		if (ft_strlen(str) >= 12)
			str += 10;
		g->id_player = str[0];
	}
}

void	ft_set_board(t_game *g, t_line *l)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = NULL;
	while (l)
	{
		str = l->str;
		if (*str && str[0] == '0')
		{
			while (*str && *str != ' ')
				str++;
			if (*str)
				str++;
			y = 0;
			while (y < g->board->y && *str)
			{
				g->board->b[x][y] = *str;
				y++;
				str++;
			}
			x++;
		}
		l = l->next;
	}
	//ft_debug_tab_b(g);
}

void	ft_set_piece(t_game *g, t_line *l)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	str = NULL;
	while (l)
	{
		str = l->str;
		y = 0;
		while (y < g->piece->y && *str)
		{
			g->piece->p[x][y] = *str;
			y++;
			str++;
		}
		x++;
		l = l->next;
	}
	//ft_debug_tab_p(g);
}
