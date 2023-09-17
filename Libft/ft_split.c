/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:09:31 by hulim             #+#    #+#             */
/*   Updated: 2023/09/17 20:20:42 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ccount(char const *s, char c)
{
	char	*ss;
	int		cnt;

	cnt = 0;
	ss = (char *) s;
	while (*ss)
	{
		while (*ss == c)
			ss++;
		if (*ss)
			cnt++;
		while (*ss != c && *ss)
			ss++;
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
	output = (char **) malloc(sizeof(char *) * (ccount(s, c) + 1));
	if (output == NULL)
		return (NULL);
	output[ccount(s, c)] = NULL;
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
