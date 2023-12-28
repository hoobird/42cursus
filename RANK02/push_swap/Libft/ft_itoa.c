/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:10:00 by hulim             #+#    #+#             */
/*   Updated: 2023/12/28 09:37:17 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	countdigits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*output;
	int		ind;
	long	nn;

	size = countdigits(n);
	output = malloc(sizeof(char) * (size + 1));
	if (output == NULL)
		return (NULL);
	output[size] = 0;
	ind = 0;
	nn = (long) n;
	if (nn < 0)
	{
		output[ind++] = '-';
		nn = -nn;
	}
	while (size > ind)
	{
		output[--size] = '0' + (nn % 10);
		nn /= 10;
	}
	return (output);
}
