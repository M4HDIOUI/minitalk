/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 01:55:53 by omahdiou          #+#    #+#             */
/*   Updated: 2023/04/10 02:07:09 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler_bonus(int sig)
{	
	(void)sig;
	write (1, "message arrive\n", 16);
}

static void	ft_sendb(int pid, char c)
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
	signal(SIGUSR1, &handler_bonus);
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
		ft_sendb(pid, argv[2][i]);
		i++;
	}
	ft_sendb(pid, '\0');
}
