/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:44:42 by hulim             #+#    #+#             */
/*   Updated: 2023/09/10 16:52:46 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	counter;

	counter = 0;
	while (*dest)
	{
		if (counter > size)
			return (size + ft_strlen(src));
		dest++;
		counter++;
	}
	while (*src)
	{
		if (counter < size - 1)
		{
			*dest = *src;
			dest++;
		}
		src++;
		counter++;
	}
	*dest = '\0';
	return (counter);
}
