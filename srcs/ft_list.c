#include "filler.h"

t_line	*ft_create_node(char *str)
{
	t_line	*l;

	if ((l = (t_line*)ft_memalloc(sizeof(t_line))) == NULL)
		ft_putstr_fd("Error malloc\n", 2);
	l->str = ft_strdup(str);
	l->next = NULL;
	return (l);
}

void	ft_list_push_back(t_line **l, char *str)
{
	t_line	*list;

	list = *l;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_node(str);
	}
	else
		*l = ft_create_node(str);
}

void	ft_clear_list(t_line **list)
{
	t_line	*l;
	t_line	*tmp;

	l = *list;
	while (l)
	{
		tmp = l;
		l = l->next;
		tmp->next = NULL;
		ft_strdel(&tmp->str);
	}
	*list = NULL;
}
