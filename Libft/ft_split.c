/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:09:31 by hulim             #+#    #+#             */
/*   Updated: 2023/09/19 17:13:02 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freeall(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		count++;
	}
	free(arr);
}

size_t	countwords(char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c)
			{
				s++;
				if (*s == 0)
					return (count);
			}
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	*ss;
	char	**output;
	char	*f;
	char	*b;
	int		i;

	i = 0;
	ss = (char *) s;
	output = (char **) malloc(sizeof(char *) * (countwords(ss, c) + 1));
	if (output == NULL)
		return (NULL);
	output[countwords(ss, c)] = NULL;
	while (*ss)
	{
		if (*ss != c)
		{
			f = ss;
			while (*ss != c && *ss)
				ss++;
			b = ss - 1;
			output[i] = malloc(sizeof(char) * (b - f + 2));
			if (output[i] == NULL)
			{
				freeall(output);
				return (NULL);
			}
			ft_strlcpy(output[i++], f, b - f + 2);
		}
		if (*ss++ == 0)
			break ;
	}
	return (output);
}
