/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:39:25 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/23 15:24:59 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	checkformat(va_list args, const char format)
{
	int	lettercount;

	lettercount = 0;
	if (format == 'c')
		lettercount += ft_putchar(va_arg(args, int));
	return (lettercount);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		lettercount;
	va_list	args;

	i = 0;
	lettercount = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lettercount += checkformat(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			lettercount++;
		}
		i++;
	}
	return (lettercount);
}
