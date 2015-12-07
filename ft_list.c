/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 22:07:15 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 21:32:59 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*ft_create_elem(char *data)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = data;
		elem->next = 0;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, char *data)
{
	t_list	*get_next;

	get_next = *begin_list;
	if (get_next != NULL)
	{
		while (get_next->next)
			get_next = get_next->next;
		get_next->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}

int		ft_size_list(t_list *list)
{
	t_list	*tmp;
	int		i;
	int		j;

	tmp = list;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->data[j++])
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_list_clear(t_list **begin_list)
{
	t_list *tmp;
	t_list *get_next;

	get_next = *begin_list;
	if (get_next != NULL)
	{
		while (get_next->next)
		{
			tmp = get_next->next;
			free(get_next);
			get_next = tmp;
		}
	}
}
