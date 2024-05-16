/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:58:39 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 03:58:55 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int i)
{
	char	*str;
	int		val;

	str = ft_itoa(i);
	val = ft_putstr(str);
	free(str);
	return (val);
}