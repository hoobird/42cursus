/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:27:00 by hulim             #+#    #+#             */
/*   Updated: 2024/04/10 18:52:11 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sendmsginbits(int pid, char *str);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Client takes 2 parameters\n");
		ft_printf("Server PID and String to send\neg: ./client (pid) (msg)\n");
		return (1);
	}
	if (sendmsginbits(ft_atoi(argv[1]), argv[2]) == -1)
		ft_printf("Error: Unable to sned signal to specified PID\n");
	return (0);
}

int	sendmsginbits(int pid, char *str)
{
	size_t	bitcount;
	int		outcome;

	while (*str)
	{
		bitcount = 0;
		while (bitcount < 8)
		{
			if (1 & (*str >> bitcount))
				outcome = kill(pid, SIGUSR1);
			else
				outcome = kill(pid, SIGUSR2);
			if (outcome == -1)
				return (outcome);
			bitcount++;
			usleep(10000);
		}
		bitcount = 0;
		str++;
	}
	return (0);
}
