/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:05 by hulim             #+#    #+#             */
/*   Updated: 2024/04/12 16:57:26 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bittochar(int sig, siginfo_t *info, void *ucontext);

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	as;

	(void) argv;
	as.sa_sigaction=&bittochar;
	sigemptyset(&as.sa_mask);
	if (argc != 1)
	{
		ft_printf("Error: Server doesn't take parameters\n");
		ft_printf("eg: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sigaction(SIGUSR1, &as, NULL);
	sigaction(SIGUSR2, &as, NULL);
	while (1)
		pause();
	return (0);
}

void	bittochar(int sig, siginfo_t *info, void *ucontext)
{
	static char		letter;
	static size_t	bitcount;
	static int		clientpid;
	static int		currpid;

	(void) ucontext;
	if (!clientpid)
		clientpid = info->si_pid;
	currpid = info->si_pid;
	if (currpid != clientpid)
	{
		bitcount = 0;
		letter = 0;
		clientpid = currpid;
	}
	if (sig == SIGUSR1)
		letter = letter | 1 << bitcount;
	bitcount++;
	kill(clientpid, SIGUSR1);
	if (bitcount == 8)
	{
		write(1, &letter, 1);
		bitcount = 0;
		letter = 0;
	}
	pause();
}
