/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:00:13 by hulim             #+#    #+#             */
/*   Updated: 2023/11/12 18:00:16 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s)
{
	char	*temp;
	int		count;

	temp = (char *) s;
	count = 0;
	while (*temp)
	{
		count++;
		temp++;
	}
	return (count);
}

int		newlinefound(char *memline)
{
	if (memline == NULL)
		return (0);
	while (*memline)
	{
		if (*memline == '\n')
			return (1);
		memline++;
	}
	return (0);
}

void    myfree(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
