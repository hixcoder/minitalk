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
	static int	binary;
	static int	i;

	if (signal == SIGUSR1)
	{
		i++;
		binary = binary * 10 +1;
	}
	else if (signal == SIGUSR2)
	{
		i++;
		binary = binary * 10;
	}
	if (i == 8)
	{
		ft_printf("%c", ft_binary_to_decimal(binary));
		i = 0;
		binary = 0;
	}
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
