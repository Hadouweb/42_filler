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

void	ft_init_board(t_game *g, char *str)
{
	t_board		*b;

	if ((b = (t_board*)ft_memalloc(sizeof(t_board))) == NULL)
		ft_putstr_fd("Error malloc\n", 2);
	g->board = b;
	str += 8;
	g->board->x = ft_atoi(str);
	while (*str && *str != ' ')
		str++;
	g->board->y = ft_atoi(str);
	g->board->b = ft_generate_tab(g->board->x, g->board->y);
}

void	ft_init_piece(t_game *g, char *str)
{
	t_piece		*p;

	if ((p = (t_piece*)ft_memalloc(sizeof(t_piece))) == NULL)
		ft_putstr_fd("Error malloc\n", 2);
	g->piece = p;
	str += 6;
	g->piece->x = ft_atoi(str);
	while (*str && *str != ' ')
		str++;
	g->piece->y = ft_atoi(str);
	g->piece->p = ft_generate_tab(g->piece->x, g->piece->y);
}