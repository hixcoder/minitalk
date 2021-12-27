/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:44:24 by hboumahd          #+#    #+#             */
/*   Updated: 2021/12/23 11:44:25 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// SIGUSR1 ==> 1
// SIGUSR2 ==> 0

void	ft_handel_error(int pid, int *bit, int *binary)
{
	static int	pid_save = 0;

	if (pid_save == 0)
		pid_save = pid;
	else if (pid_save != pid)
	{
		pid_save = 0;
		*bit = 0;
		*binary = 0;
	}
}

void	ft_signal_handler(int signal, siginfo_t *info, void *nothing)
{
	static int	binary = 0;
	static int	bit = 0;

	ft_handel_error(info->si_pid, &bit, &binary);
	bit++;
	(void)nothing;
	if (signal == SIGUSR1)
		binary = binary * 10 + 1;
	else if (signal == SIGUSR2)
		binary = binary * 10;
	if (bit == 8)
	{
		ft_printf("%c", ft_binary_to_decimal(binary));
		bit = 0;
		binary = 0;
	}
}

int	main(void)
{
	struct sigaction	new_action;

	ft_printf("PID: %d\n", getpid());
	new_action.sa_sigaction = ft_signal_handler;
	new_action.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &new_action, NULL);
		sigaction(SIGUSR2, &new_action, NULL);
		pause();
	}	
}
