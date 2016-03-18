#include "filler.h"

int		ft_check_mode(t_app *app, char *str)
{
	if (ft_strlen(str) >= 7 && ft_strstr(str, "Plateau"))
	{
		app->mode = 1;
		ft_init_board(app, str);
		return (1);
	}
	else if (ft_strlen(str) >= 5 && ft_strstr(str, "Piece"))
	{
		app->mode = 2;
		ft_init_piece(app, str);
		return (1);
	}
	return (0);
}
