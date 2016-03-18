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

void	ft_print(int x, int y)
{
	char	*str_x;
	char	*str_y;

	str_x = ft_itoa(x);
	str_y = ft_itoa(y);
	write(1, str_x, ft_strlen(str_x));
	write(1, " ", 1);
	write(1, str_y, ft_strlen(str_y));
	write(1, "\n", 1);
}
