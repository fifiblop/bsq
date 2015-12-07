/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_saruman.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 21:25:56 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 21:16:50 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_saruman(char *filename)
{
	char	*str_grid;
	t_info	grid_info;
	char	**grid;
	int		**gridint;
	int		x;

	str_grid = ft_str_map(filename);
	grid_info = ft_make_grid_info(str_grid);
	x = ft_check_error(str_grid, grid_info);
	if (x == 0)
	{
		ft_putstr("map error");
		return ;
	}
	grid = ft_make_grid(str_grid, grid_info);
	free(str_grid);
	gridint = ft_convert(grid, grid_info);
	gridint = ft_resolve(gridint, grid_info);
	grid = ft_square(gridint, grid_info);
	ft_print_bsq(grid, grid_info);
	free(grid);
	free(gridint);
}
