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
// SIGUSR1 ==> 0
void	ft_signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else if (signal == SIGUSR2)
		ft_printf("0");
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_signal_handler);
		signal(SIGUSR2, ft_signal_handler);
		pause();
	}
}
