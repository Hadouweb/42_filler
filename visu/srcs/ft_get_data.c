#include "visu.h"

void	ft_init_board_or_piece(t_app *app, char *str)
{
	if (ft_strstr(str, "Plateau"))
	{
		if (!app->board.x)
		{
			app->board.y = ft_atoi(str += 8);
			app->board.x = ft_atoi(str += 2);
		}
		app->mode = 1;
	}
	else if (ft_strstr(str, "Piece"))
	{
		app->piece.y = ft_atoi(str += 6);
		app->piece.x = ft_atoi(str += 2);
		app->mode = 2;
	}
}

void	ft_set_player(t_app *app, char *str)
{
	t_player	p;
	int			i;
	int			start;

	if (ft_strlen(str) > 11)
		str += 10;
	p.id = ft_atoi(str);
	i = 0;
	start = 0;
	while (str[i])
	{
		start++;
		if (str[i] == '/')
			start = 0;
		i++;
	}
	str = (&str[i] - start);
	p.name = ft_strndup(str, ft_strlen(str) - 1);
	if (p.id == 1)
		app->p1 = p;
	if (p.id == 2)
		app->p2 = p;
}
