#include "visu.h"

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

void	ft_print_data(void *p)
{
	ft_putstr((char*)p);
}
