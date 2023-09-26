/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:45:52 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/26 01:27:36 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int a = 10;
	int *b = &a;
	int len;
	char *ss = NULL;
	len = printf("real: %c %s", 'c', "goodbye world");
	printf(" | len: %d\n", len);
	len = ft_printf("ft  : %c %s", 'c', "goodbye world");
	printf(" | len: %d\n", len);
	len = printf("real: %p", b);
	printf(" | len: %d\n", len);
	len = ft_printf("ft  : %p", b);
	printf(" | len: %d\n", len);
	ft_printf("%s\n", ss);
	return (0);
}
