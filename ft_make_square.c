/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddjian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 18:16:33 by ddjian            #+#    #+#             */
/*   Updated: 2015/08/27 17:50:39 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_find_max(int **grid, t_info grid_info)
{
	int		x;
	int		y;
	int		tmp;

	x = 0;
	y = 0;
	tmp = grid[x][y];
	while (x < grid_info.line)
	{
		y = 0;
		while (y < grid_info.column)
		{
			if (grid[x][y] > tmp)
				tmp = grid[x][y];
			y++;
		}
		x++;
	}
	return (tmp);
}

char	**ft_do_square(char **grid, t_info grid_info, int nb)
{
	t_sq	sq;

	sq.i = 0;
	sq.v = 0;
	while (sq.i < grid_info.line)
	{
		sq.j = 0;
		while (sq.j < grid_info.column)
		{
			if (grid[sq.i][sq.j] == grid_info.square_char && sq.v++ == 0)
			{
				sq.pos_x = sq.i;
				sq.pos_y = sq.j;
			}
			else if (sq.v > 0 && sq.i >= sq.pos_x && sq.i <= (sq.pos_x + nb - 1)
				&& sq.j >= sq.pos_y && sq.j <= (sq.pos_y + nb - 1))
				grid[sq.i][sq.j] = grid_info.square_char;
			sq.j++;
		}
		sq.i++;
	}
	return (grid);
}

char	**ft_create_double_grid(int **grid, t_info grid_info)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char*) * (grid_info.line + 1));
	tab[grid_info.line + 1] = NULL;
	i = 0;
	while (i < grid_info.line)
	{
		tab[i] = malloc(sizeof(char) * (grid_info.column + 1));
		tab[i][grid_info.column + 1] = '\0';
		i++;
	}
	return (tab);
}

char	**ft_square(int **grid, t_info grid_info)
{
	int		i;
	int		j;
	char	**tab;
	int		tmp;
	int		v;

	tmp = ft_find_max(grid, grid_info);
	tab = ft_create_double_grid(grid, grid_info);
	i = 0;
	v = 0;
	while (i < grid_info.line)
	{
		j = 0;
		while (j < grid_info.column)
		{
			if (grid[i][j] == tmp && v++ == 0)
				tab[i][j++] = grid_info.square_char;
			else if (grid[i][j] == 0)
				tab[i][j++] = grid_info.bloc_char;
			else
				tab[i][j++] = grid_info.empty_char;
		}
		i++;
	}
	return (ft_do_square(tab, grid_info, tmp));
}
