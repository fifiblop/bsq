/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bsq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddjian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 10:22:43 by ddjian            #+#    #+#             */
/*   Updated: 2015/08/27 21:12:38 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_bsq(char **grid, t_info grid_info)
{
	int		x;
	char	nl;

	nl = '\n';
	x = 0;
	while (x < grid_info.line)
	{
		write(1, grid[x], grid_info.column);
		write(1, &nl, 1);
		x++;
	}
}
