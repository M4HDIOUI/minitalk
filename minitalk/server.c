/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:18:08 by omahdiou          #+#    #+#             */
/*   Updated: 2023/04/10 02:18:01 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	shifting(int signal, unsigned char *c, int *i, int or_oper)
{	
	if (signal == SIGUSR1)
	{
		or_oper = 1 << *i;
		*c = *c | or_oper;
	}
}

void	handler(int signum, siginfo_t *info, void *extra)
{
	static int				pidcheck;
	static unsigned char	c;
	static int				i;
	int						or_oper;

	or_oper = 0;
	(void)extra;
	if (pidcheck != info->si_pid)
	{
		c = '\0';
		i = 0;
		pidcheck = info->si_pid;
	}
	shifting(signum, &c, &i, or_oper);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = '\0';
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
