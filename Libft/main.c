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

#include "libft.h"
#include <stdio.h>

int main()
{
	char s1[30] = "pen pineapple apple pen!";

	char* ptr = ft_strnstr(s1, "pine", 10);
	printf("%s\n", ptr);
	//char* ptr1 = ft_strnstr(s1, "pine", 5);
	//printf("%s\n", ptr1);
	char* ptr2 = NULL;
	printf("%s\n", ptr2);

	return (0);
}
