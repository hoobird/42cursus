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

char	*ft_strchr(const char *s, int c)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(s);
	while (count <= len)
	{
		if (s[count] == (unsigned char) c)
		{
			return ((char *)&s[count]);
		}
		count++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		count;
	char	*temp;

	count = 0;
	temp = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	while ((size_t) count < ft_strlen(s))
	{
		temp[count] = s[count];
		count++;
	}
	return (temp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

