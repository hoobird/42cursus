/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:09:08 by hulim             #+#    #+#             */
/*   Updated: 2023/09/17 17:52:47 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char c, char const *set)
{
	int	counter;

	counter = 0;
	while (set[counter])
	{
		if (c == set[counter])
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*front;
	char	*back;
	char	*output;
	int		i;

	if (!s1 || !set)
		return (NULL);
	front = (char *) s1;
	back = front;
	while (*(back + 1))
		back++;
	while (isset(*front, set))
		front++;
	while (isset(*back, set))
		back--;
	if (back < front)
		return ("");
	output = malloc(sizeof(char) * (back - front + 2));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (front <= back)
		output[i++] = *front++;
	output[i] = 0;
	return (output);
}
