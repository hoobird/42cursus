/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:02:06 by hulim             #+#    #+#             */
/*   Updated: 2023/09/10 20:14:08 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ss1;
	const char	*ss2;

	ss1 = (const char *) s1;
	ss2 = (const char *) s2;
	return (ft_strncmp(ss1, ss2, n));
}
