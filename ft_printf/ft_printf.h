/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoobird <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:22:31 by hoobird           #+#    #+#             */
/*   Updated: 2023/09/23 11:31:41 by hoobird          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int     checkformat(va_list args, const char format);

#endif
