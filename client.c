/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:44:15 by hboumahd          #+#    #+#             */
/*   Updated: 2021/12/23 11:44:17 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// SIGUSR1 ==> 1
// SIGUSR2 ==> 0

void	ft_send_binary_to_server(char *text, int pid)
{
	int		i;
	int		bit_shift;

	i = -1;
	while (text[++i])
	{
		bit_shift = -1;
		while (++bit_shift < 8)
		{
			if (text[i] & 128 >> bit_shift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(800);
		}
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			printf("\n==> Please enter a valid PID!\n\n");
		else
			ft_send_binary_to_server(av[2], pid);
	}
	else
		printf("\n==> Please enter the \"The PID\" and \"The string to send\" !\n\n");
	return (0);
}
