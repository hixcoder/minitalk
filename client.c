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
			usleep(600);
		}
	}
	i = 8;
	while (i > 0)
	{
		kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	ft_signal_handler(int signal)
{
	(void)signal;
	ft_printf("the message is received!\n");
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		signal(SIGUSR1, ft_signal_handler);
		pid = ft_atoi(av[1]);
		ft_send_binary_to_server(av[2], pid);
	}
	else
		printf("Please enter the \"PID\" and \"the text\"!\n");
	return (0);
}
