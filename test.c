/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboumahd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:29:24 by hboumahd          #+#    #+#             */
/*   Updated: 2021/12/23 15:29:26 by hboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int tow_power(int i)
{
	int nb;

	nb = 1;
	while (i > 0)
	{
		nb *= 2;
		i--;
	}
	return (nb);
}

int ft_binary_to_decimal(int n)
{
	int dec;
	int i;
	int remain;

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

int main()
{
	int b = 1100001;

	printf("%c\n", ft_binary_to_decimal(b));
	return (0);
}
