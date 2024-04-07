/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulim <hulim@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:27:00 by hulim             #+#    #+#             */
/*   Updated: 2024/04/08 02:41:55 by hulim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Error: Client takes 2 parameters\n");
		ft_printf("Server PID and String to send\neg: ./client (pid) (msg)\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	ft_printf("%d : %s\n", pid, message);
}
