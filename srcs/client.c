/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:20:13 by tglory            #+#    #+#             */
/*   Updated: 2021/11/17 17:46:08 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/**
 * Return -1 if an error has occurred otherwise 0
 */
static int	send_byte(int pid, unsigned char byte, int position)
{
	if (position > 0 && send_byte(pid, byte / 2, position - 1) == -1)
		return (-1);
	if (usleep(800) == -1)
		return (-1);
	if (byte % 2)
		return (kill(pid, SIGUSR2));
	else
		return (kill(pid, SIGUSR1));
}

static int	check_arg(int ac, char **av)
{
	int	*pid;
	
	if (ac < 3)
	{
		printf("The 1st must be the PID of the server. " \
			"The 2nd argument must be a string.\n");
		exit(1);
	}
	pid = ft_atoi_utimate(av[1]);
	if (!pid || *pid <= 0)
	{
		printf("The 1st must be the PID of the server.\n");
		exit(1);
	}
	return (*pid);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	pid = check_arg(ac, av);
	str = av[2];
	while (*str)
	{
		if (send_byte(pid, *str, 7) == -1)
		{
			printf("An error has occurred when sending the '%c'.\n", *str);
			return (1);
		}
		str++;
	}
	if (send_byte(pid, 0, 7) == -1)
	{
		printf("An error has occurred when sending the end signal.");
		return (1);
	}
	printf("Send to the server successfully\n");
	return (0);
}
