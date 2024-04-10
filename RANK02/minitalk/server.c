/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:56:05 by hulim             #+#    #+#             */
/*   Updated: 2024/04/11 01:36:47 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bittochar(int sigusr);
void sendletter(char letter);

int	main(int argc, char **argv)
{
	int		pid;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error: Server doesn't take parameters\n");
		ft_printf("eg: ./server\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	signal(SIGUSR1, bittochar);
	signal(SIGUSR2, bittochar);
	while (1)
		pause();
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
		sendletter(letter);
		bitcount = 0;
		letter = 0;
	}
}

void printcontent(void *content)
{
	char	*c;
	
	c = (char*) content;
	write(1, c, 1);	
}

void sendletter(char letter)
{
	static t_list *head;

	if (head == NULL)
		ft_lstnew("");
	if (letter == 0)
		return (ft_lstiter(head, printcontent));
	ft_lstadd_back(&head, ft_lstnew(&letter));
}
