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

#include <sys/types.h>

int	main(int ac, char **av)
{
	int pid;

	if (ac == 3)
	{
		ft_printf("the server PID: %s \n", av[1]);
		ft_printf("The string to send: %s \n", av[2]);
	}
	else
		ft_printf("please enter 2 parameters!\n");
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);	
	
	return (0);
}
