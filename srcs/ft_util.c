#include "filler.h"

void	ft_print(int y, int x)
{
	char	*str_y;
	char	*str_x;

	str_y = ft_itoa(y);
	str_x = ft_itoa(x);
	write(1, str_y, ft_strlen(str_y));
	write(1, " ", 1);
	write(1, str_x, ft_strlen(str_x));
	write(1, "\n", 1);
}

void	ft_clear_list(t_app *app)
{
	t_list	*l;
	t_list	*tmp;

	l = app->list_tmp;
	tmp = NULL;
	while (l)
	{
		free(l->content);
		l->content = NULL;
		l->content_size = 0;
		tmp = l;
		free(l);
		l = tmp->next;
	}
	app->list_tmp = NULL;
}

void	ft_clear_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab && tab[0])
	{	
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
}
