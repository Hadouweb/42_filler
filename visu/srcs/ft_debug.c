#include "visu.h"

void	ft_debug_player(t_app *app)
{
	printf("Joueur 1 : id : %d, name : %s\n", app->p1.id, app->p1.name);
	printf("Joueur 2 : id : %d, name : %s\n", app->p2.id, app->p2.name);
}

void	ft_debug_board(t_app *app)
{
	int		i;
	int		j;
	char	**tab;

	tab = app->board.tab;
	printf("_Taille du plateau : y = %d, x = %d\n", app->board.y, app->board.x);
	i = 0;
	while (i < app->board.y)
	{
		j = 0;
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_debug_piece(t_app *app)
{
	int		i;
	int		j;
	char	**tab;

	tab = app->piece.tab;
	printf("_Taille de la piece : y = %d, x = %d\n", app->piece.y , app->piece.x );
	i = 0;
	while (i < app->piece.y )
	{
		j = 0;
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_debug_lst(t_app *app)
{
	t_list	*l;

	l = app->list_tmp;
	while (l)
	{
		printf("%s\n", l->content);
		l = l->next;
	}
}
