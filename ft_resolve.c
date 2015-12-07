/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddjian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 12:41:07 by ddjian            #+#    #+#             */
/*   Updated: 2015/08/27 17:06:23 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		**ft_convert(char **grid, t_info grid_info)
{
	int		x;
	int		y;
	int		**tab;

	tab = malloc(sizeof(int*) * (grid_info.line));
	x = 0;
	while (x < grid_info.line)
	{
		y = 0;
		tab[x] = malloc(sizeof(int) * (grid_info.column));
		while (y < grid_info.column)
		{
			if (grid[x][y] != grid_info.bloc_char &&
				(x == (grid_info.line - 1) || y == (grid_info.column - 1)))
				tab[x][y] = 1;
			else if (grid[x][y] == grid_info.bloc_char)
				tab[x][y] = 0;
			else if (grid[x][y] == grid_info.empty_char)
				tab[x][y] = -1;
			y++;
		}
		x++;
	}
	return (tab);
}

void	ft_conditions(int **grid, t_info grid_info, int x, int y)
{
	int		a;
	int		b;
	int		c;

	a = grid[x + 1][y];
	b = grid[x + 1][y + 1];
	c = grid[x][y + 1];
	if (a >= b && b >= c)
		grid[x][y] = c + 1;
	else if (a >= c && c >= b)
		grid[x][y] = b + 1;
	else if (b >= a && a >= c)
		grid[x][y] = c + 1;
	else if (b >= c && c >= a)
		grid[x][y] = a + 1;
	else if (c >= a && a >= b)
		grid[x][y] = b + 1;
	else if (c >= b && b >= a)
		grid[x][y] = a + 1;
}

int		**ft_resolve(int **grid, t_info grid_info)
{
	int		x;
	int		y;

	x = grid_info.line - 2;
	while (x >= 0)
	{
		y = grid_info.column - 2;
		while (y >= 0)
		{
			if (grid[x][y] != 0)
				ft_conditions(grid, grid_info, x, y);
			y--;
		}
		x--;
	}
	return (grid);
}
