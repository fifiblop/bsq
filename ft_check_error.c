/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddjian <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 15:44:46 by ddjian            #+#    #+#             */
/*   Updated: 2015/08/27 21:05:10 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_check_line(char *str, t_info grid_info)
{
	int	x;

	x = ft_send_i(str);
	while (str[x])
	{
		if (str[x] == '\n' || str[x + 1] == '\0')
			x += grid_info.column + 1;
		else
			return (0);
	}
	return (1);
}

int		ft_check_error(char *str, t_info grid_info)
{
	int		x;

	x = grid_info.column;
	if (grid_info.square_char == grid_info.bloc_char || grid_info.bloc_char ==
		grid_info.empty_char || grid_info.square_char == grid_info.empty_char)
		return (0);
	if (grid_info.line < 1 && grid_info.column < 1)
		return (0);
	if (ft_check_line(str, grid_info) == 0)
		return (0);
	x = grid_info.column;
	while (str[x])
	{
		if (str[x] != '\n' && str[x] != grid_info.line && str[x] !=
				grid_info.empty_char && str[x] != grid_info.bloc_char &&
				str[x] != '\0')
			return (0);
		x++;
	}
	return (1);
}
