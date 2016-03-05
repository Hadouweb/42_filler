#include "filler.h"

int		ft_check_mode(t_game *g, char *str)
{
	if (ft_strlen(str) >= 7 && ft_strstr(str, "Plateau"))
	{
		g->mode = 1;
		ft_init_board(g, str);
		return (1);
	}
	else if (ft_strlen(str) >= 5 && ft_strstr(str, "Piece"))
	{
		g->mode = 2;
		ft_init_piece(g, str);
		return (1);
	}
	return (0);
}
