/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:14:47 by hulim             #+#    #+#             */
/*   Updated: 2023/09/10 17:29:07 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(s);
	while (count <= len)
	{
		if (s[count] == c)
		{
			return (&((char *)s)[count]);
		}
		count++;
	}
	return (0);
}
