/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:32:01 by omahdiou          #+#    #+#             */
/*   Updated: 2023/04/10 01:45:42 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send(int pid, char c)
{
	int			n;
	static int	bit;

	n = 1;
	while (bit < 8)
	{
		if ((n & c) == 0)
			kill (pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(700);
		bit++;
		c = c >> 1;
	}
	if (bit == 8)
		bit = 0;
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		write(1, "syntax error !\n", 14);
		exit(1);
	}
	pid = ft_atoi(argv [1]);
	if (pid < 0)
	{
		write(1, "bad pid", 7);
		exit(1);
	}
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
}
