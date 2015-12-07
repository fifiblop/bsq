/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 15:06:44 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 19:22:48 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*ft_get_grid(char *filename)
{
	int		fd;
	int		ret;
	char	buf[4096];
	t_list	*list;

	list = NULL;
	fd = open(filename, O_RDONLY);
	while ((ret = read(fd, buf, 4096)))
	{
		buf[ret] = '\0';
		ft_list_push_back(&list, ft_strdup(buf));
	}
	close(fd);
	return (list);
}

t_list	*ft_get_grid_stdi(void)
{
	int		ret;
	char	buf[4096];
	t_list	*list;

	list = NULL;
	while ((ret = read(0, buf, 4096)))
	{
		buf[ret] = '\0';
		ft_list_push_back(&list, ft_strdup(buf));
	}
	return (list);
}

char	*ft_str_map(char *filename)
{
	t_list	*list;
	char	*str_map;
	int		i;
	int		j;

	list = ft_get_grid(filename);
	str_map = malloc(sizeof(char) * ft_size_list(list) + 1);
	i = 0;
	while (list)
	{
		j = 0;
		while (list->data[j])
		{
			str_map[i++] = list->data[j++];
		}
		list = list->next;
	}
	str_map[i] = '\0';
	ft_list_clear(&list);
	return (str_map);
}

char	*ft_str_map_stdi(void)
{
	t_list	*list;
	char	*str_map;
	int		i;
	int		j;

	list = ft_get_grid_stdi();
	str_map = malloc(sizeof(char) * ft_size_list(list) + 1);
	i = 0;
	while (list)
	{
		j = 0;
		while (list->data[j])
		{
			str_map[i++] = list->data[j++];
		}
		list = list->next;
	}
	str_map[i] = '\0';
	ft_list_clear(&list);
	return (str_map);
}
