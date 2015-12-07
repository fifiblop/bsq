/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 14:47:00 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/27 17:26:02 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_info	ft_make_grid_info(char *str_grid)
{
	t_info	grid_info;
	int		p;
	int		i;
	char	*nb_line;

	p = 0;
	i = ft_send_i(str_grid);
	grid_info.square_char = str_grid[i - 1];
	grid_info.bloc_char = str_grid[i - 2];
	grid_info.empty_char = str_grid[i - 3];
	nb_line = malloc(sizeof(char) * (i - 3));
	nb_line[i - 3] = '\0';
	while (p < (i - 3))
	{
		nb_line[p] = str_grid[p];
		p++;
	}
	grid_info.line = ft_atoi(nb_line);
	grid_info.column = ft_send_t(str_grid, i);
	return (grid_info);
}

char	**ft_make_grid(char *str_grid, t_info grid_info)
{
	char	**grid;
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	grid = malloc(sizeof(char*) * (grid_info.line + 1));
	if (grid)
	{
		while (str_grid[i] != '\n')
			i++;
		i++;
		while (y < grid_info.line)
		{
			x = 0;
			grid[y] = malloc(sizeof(char) * (grid_info.column + 1));
			while (x <= grid_info.column)
				grid[y][x++] = str_grid[i++];
			grid[y++][x] = '\0';
		}
	}
	return (grid);
}
