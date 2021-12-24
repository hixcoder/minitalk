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

char	*ft_ascii_to_binary(int c)
{
	int		bit;
	char	*binary;

	bit = -1;
	binary = malloc(8);
	if (!binary)
		return (NULL);
	while (++bit < 8)
	{
		if (c & 128 >> bit)
			binary[bit] = '1';
		else
			binary[bit] = '0';
	}
	return (binary);
}

char	*ft_asciitext_to_binarytext(char *asciitext)
{
	int		asciitext_len;
	int		i;
	char	*binarytext;

	asciitext_len = ft_strlen(asciitext);
	binarytext = malloc(asciitext_len * 8);
	if (!binarytext)
		return (NULL);
	i = -1;
	binarytext[0] = '\0';
	while (asciitext[++i])
		binarytext = ft_strjoin(binarytext, ft_ascii_to_binary(asciitext[i]));
	return (binarytext);
}

void	ft_send_binary_to_server(char *binary_text, int pid)
{
	int	i;

	i = -1;
	while (binary_text[++i])
	{
		if (binary_text[i] == '0')
			kill(pid, SIGUSR1);
		else if (binary_text[i] == '1')
			kill(pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		ft_printf("the server PID: %s \n", av[1]);
		ft_printf("The text: %c \n", av[2][0]);
		ft_printf("The binary : %s \n", ft_asciitext_to_binarytext(av[2]));
	}
	else
		ft_printf("please enter 2 !\n");
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);
	return (0);
}
