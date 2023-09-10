/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*       .c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:58:52 by hulim             #+#    #+#             */
/*   Updated: 2023/09/07 15:59:18 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <assert.h>

int main() {
	char dest[10];
	char *src = "hello Worlds";

	ft_memset(dest, '2', 5);
	//printf("%s\n",src);
	printf("%s\n",dest);

	//assert(strcmp(dest, src) == 0);

    return 0;
}
