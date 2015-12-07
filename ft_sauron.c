/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sauron.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 14:45:21 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 15:00:18 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_sauron(void)
{
	char	*str_grid;
	t_info	grid_info;
	char	**grid;
	int		**gridint;

	str_grid = ft_str_map_stdi();
	grid_info = ft_make_grid_info(str_grid);
	grid = ft_make_grid(str_grid, grid_info);
	free(str_grid);
	gridint = ft_convert(grid, grid_info);
	gridint = ft_resolve(gridint, grid_info);
	grid = ft_square(gridint, grid_info);
	ft_print_bsq(grid, grid_info);
}
