#include "filler.h"

char	**ft_generate_tab(int x, int y)
{
	char	**tab;
	int		i;

	if ((tab = (char**)ft_memalloc(x * sizeof(char *))) == NULL)
		ft_putstr_fd("Error malloc\n", 2);
	i = 0;
	while (i < x)
	{
		if ((tab[i] = (char*)ft_memalloc(y)) == NULL)
			ft_putstr_fd("Error malloc\n", 2);
		i++;
	}
	return (tab);
}

void	ft_init_board(t_app *app, char *str)
{
	str += 8;
	app->board.x = ft_atoi(str);
	while (*str && *str != ' ')
		str++;
	app->board.y = ft_atoi(str);
	app->board.tab = ft_generate_tab(app->board.x, app->board.y);
}

void	ft_init_piece(t_app *app, char *str)
{
	str += 6;
	app->piece.x = ft_atoi(str);
	while (*str && *str != ' ')
		str++;
	app->piece.y = ft_atoi(str);
	app->piece.tab = ft_generate_tab(app->piece.x, app->piece.y);
}