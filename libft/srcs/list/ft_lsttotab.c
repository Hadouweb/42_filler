/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttotab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 00:32:17 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 03:18:59 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	**ft_lsttotab(t_list *l)
{
	char	**tab;
	int		size;
	size_t	i;
	t_list	*list;

	list = l;
	size = ft_lstsize(l);
	i = 0;
	if ((tab = (char **)ft_memalloc(size * sizeof(char *))) == NULL)
		return (NULL);
	while (list)
	{
		if ((tab[i] = (char *)ft_memalloc(list->content_size)) == NULL)
			return (NULL);
		tab[i] = ft_strdup(list->content);
		list = list->next;
		i++;
	}
	return (tab);
}
