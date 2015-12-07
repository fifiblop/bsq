/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdelefos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/13 20:11:42 by pdelefos          #+#    #+#             */
/*   Updated: 2015/08/14 12:50:30 by pdelefos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		size;
	int		j;
	char	*str;

	size = 0;
	j = 0;
	while (src[size])
		size++;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str == 0)
		return (0);
	while (src[j])
	{
		str[j] = src[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
