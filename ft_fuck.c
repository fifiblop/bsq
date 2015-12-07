/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 17:10:30 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 17:23:08 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_send_i(char *str_grid)
{
	int	i;

	i = 0;
	while (str_grid[i] != '\n')
		i++;
	return (i);
}

int		ft_send_t(char *str_grid, int i)
{
	int	t;
	int l;

	l = 0;
	i = ft_send_i(str_grid);
	t = i + 1;
	while (str_grid[t] != '\n')
	{
		t++;
		l++;
	}
	return (l);
}
