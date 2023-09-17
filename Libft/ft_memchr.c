/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 19:44:41 by hulim             #+#    #+#             */
/*   Updated: 2023/09/17 16:45:37 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;

	temp = (char *) s;
	while (n > 0 && *temp)
	{
		if (*temp == c)
			return (temp);
		n--;
		temp++;
	}
	if (*temp == c && c == 0)
		return (temp);
	return (0);
}
