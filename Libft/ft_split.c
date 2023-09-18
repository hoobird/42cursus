/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:09:31 by hulim             #+#    #+#             */
/*   Updated: 2023/09/19 04:16:59 by hoobird          ###   ########.fr       */
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

int	ccount(char *s, char c)
{
	int		cnt;

	cnt = 1;
	if (ft_strlen(s) == 0)
		return (0);
	while (*s)
	{
		if (*s == c)
		{
			cnt++;
			while (*s == c)
				s++;
		}
		s++;
	}
	return (cnt);
	}

char	**ft_split(char const *s, char c)
{
	char	**output;
	int		space;
	char	*frt;
	char	*temp;

	space = 0;
	output = (char **) malloc(sizeof(char *) * (ccount((char *)s, c) + 1));
	if (output == NULL)
		return (NULL);
	output[ccount((char *)s, c)] = NULL;
	temp = (char *) s;
	while (*temp)
	{
		if (*temp != c)
		{
			frt = temp;
			while (*temp != c && *temp != 0)
				temp++;
			output[space] = malloc(sizeof(char) * ((temp - 1) - frt + 2));
			ft_strlcpy(output[space++], frt, (temp - 1) - frt + 2); 
		}
		temp++;
	}
	return (output);
}
