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

void	ft(int signal)
{
	if (signal == SIGUSR1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, ft);
	signal(SIGUSR2, ft);
	while (1)
	{
		pause();
	}
}
