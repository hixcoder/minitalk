/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 20:05:56 by hboumahd          #+#    #+#             */
/*   Updated: 2021/12/24 20:05:59 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r'))
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int	tow_power(int i)
{
	int	nb;

	nb = 1;
	while (i > 0)
	{
		nb *= 2;
		i--;
	}
	return (nb);
}

int	ft_binary_to_decimal(int n)
{
	int	dec;
	int	i;
	int	remain;

	i = 0;
	dec = 0;
	while (n != 0)
	{
		remain = n % 10;
		n = n / 10;
		dec += remain * tow_power(i);
		i++;
	}
	return (dec);
}
