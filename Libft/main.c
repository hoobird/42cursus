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
  char str1[] = "This is a test.";
  char str2[] = "This is another test.";

  int result;

  result = ft_memcmp(str1, str2, 17);

  if (result == 0) {
    printf("The strings are equal.\n");
  } else if (result < 0) {
    printf("The first string is less than the second string.\n");
  } else {
    printf("The first string is greater than the second string.\n");
  }

  return 0;
}
