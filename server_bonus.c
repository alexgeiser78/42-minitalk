/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:24:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/05 18:13:36 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minitalk_bonus.h"

static void	print_bonus_msg(int signal)
{
	static int	bit;
	static int	character;

//
	if (signal == SIGUSR1)
		character += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(character, 1);
//
//
		bit = 0;
		character = 0;
	}
}





int	main(void)
{
	pid_t	my_pid_bonus;
	struct sigaction	sa_newsig1; // a mettre dans minitalk_bonus.h si possible
	struct sigaction	sa_newsig2;
	my_pid_bonus = getpid();

	ft_printf("Bonus Server PID = %d\n", (int)my_pid_bonus);
	sa_newsig1.sa_flags = SA_SIGINFO;
	sa_newsig1.sa_sigaction = print_bonus_msg;
	sigaction(SIGUSR1, &sa_newsig1, NULL);
	sa_newsig2.sa_flags = SA_SIGINFO;
	sa_newsig2.sa_sigaction = print_bonus_msg;
	sigaction(SIGUSR2, &sa_newsig2, NULL);

	while(1)
		pause();
	return (0);
}

//sigaction = used to change the action taken by a process on receipt
//of a specific signal, works as a struct
//int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
//signum specifies the signal 
//sa_newsig = user defined word -> action created by sigaction
//SA_SIGINFO = the signal handler will receive 3 args instead of 1, also
//works as a struct
//sa_flags = special flags to affect funcion of signal (int)
