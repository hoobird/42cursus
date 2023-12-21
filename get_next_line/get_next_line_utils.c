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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		totallen;
	char	*temp;

	i = 0;
	totallen = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * (totallen + 1));
	if (temp == NULL)
		return (NULL);
	while (*s1)
	{
		temp[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		temp[i] = *s2;
		i++;
		s2++;
	}
	temp[i] = '\0';
	return (temp);
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[count] != 0 && count < (size -1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = 0;
	return (ft_strlen(src));
}