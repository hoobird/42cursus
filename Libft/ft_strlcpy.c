/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:47:09 by hulim             #+#    #+#             */
/*   Updated: 2023/09/10 17:02:25 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int		counter;
	size_t				len;

	len = ft_strlen(src);
	counter = 0;
	while (counter < size - 1 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		counter++;
	}
	*dest = 0;
	return (len);
}
