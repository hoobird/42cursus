/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:52:14 by hoobird           #+#    #+#             */
/*   Updated: 2023/12/28 09:37:17 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	isspacee(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	char	*temp;
	int		isnegative;
	int		number;

	isnegative = -1;
	number = 0;
	temp = (char *) nptr;
	while (isspacee(*temp))
		temp++;
	if (*temp == '-')
	{
		isnegative *= -1;
		temp++;
	}
	else if (*temp == '+')
		temp++;
	while (*temp >= '0' && *temp <= '9')
	{
		number = number * 10 + (*temp - '0');
		temp++;
	}
	if (isnegative > 0)
		number *= -1;
	return (number);
}