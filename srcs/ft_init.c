#include "filler.h"

void	ft_init_board(t_app *app, char *str)
{
	str += 8;
	app->board.y = ft_atoi(str);
	while (*str && *str != ' ')
		str++;
	app->board.x = ft_atoi(str);
}

void	ft_init_piece(t_app *app, char *str)
{
	str += 6;
	app->piece.y = ft_atoi(str);
	while (*str && *str != ' ')
		str++;
	app->piece.x = ft_atoi(str);
}