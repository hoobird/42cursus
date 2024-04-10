/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:05 by hulim             #+#    #+#             */
/*   Updated: 2024/04/10 18:40:32 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bittochar(int sigusr);

int	main(int argc, char **argv)
{
	int	pid;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error: Server doesn't take parameters\n");
		ft_printf("eg: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, bittochar);
		signal(SIGUSR2, bittochar);
		pause();
	}
	return (0);
}

void	bittochar(int sigusr)
{
	static char		letter;
	static size_t	bitcount;
	unsigned char	mask;

	if (sigusr == SIGUSR1)
	{
		mask = 1 << bitcount;
		letter = letter | mask;
	}
	bitcount++;
	if (bitcount == 8)
	{
		ft_printf("%c", letter);
		bitcount = 0;
		letter = 0;
	}
}
