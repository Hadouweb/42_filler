#include "filler.h"

void	ft_clear_list(t_list **list)
{
	t_list	*l;
	t_list	*tmp;

	l = *list;
	while (l)
	{
		tmp = l;
		l = l->next;
		tmp->next = NULL;
		ft_memdel(&tmp->content);
	}
	*list = NULL;
}
