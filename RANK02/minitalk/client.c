/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:27:00 by hulim             #+#    #+#             */
/*   Updated: 2024/04/11 01:39:30 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		sendmsginbits(int pid, char *str);
int		checkpidisnum(char *pid);
void	sendendingnull(int pid);

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Error: Client takes 2 parameters\n");
		ft_printf("Server PID and String to send\neg: ./client (pid) (msg)\n");
		return (1);
	}
	if ((checkpidisnum(argv[1]) == 0) ||
		(sendmsginbits(ft_atoi(argv[1]), argv[2]) == -1))
		ft_printf("Error: Unable to send signal to specified PID\n");
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
			usleep(100);
		}
		bitcount = 0;
		str++;
		usleep(100);
	}
	sendendingnull(pid);
	return (0);
}

void	sendendingnull(int pid)
{
	size_t	bitcount;
	int		outcome;

	bitcount = 0;
	while (bitcount < 8)
	{
		outcome = kill(pid, SIGUSR2);
		if (outcome == -1)
			return;
		bitcount++;
		usleep(100);
	}
}

int	checkpidisnum(char *pid)
{
	while (*pid)
	{
		if (*pid < '0' || *pid > '9')
			return (0);
		pid++;
	}
	return (1);
}
