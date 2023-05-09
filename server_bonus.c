/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:24:58 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/09 15:49:02 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static	void	new_action_to_sig(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	character;

	(void)context;
	if (signum == SIGUSR1)
		character |= (0b1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		if (character == '\0')
			kill(info->si_pid, SIGUSR1);
		character = 0;
		bit = 0;
	}
}

// siginfo_t = struct linked to SA_SIGINFO
//0b1 = binary number 1 or 00000001
//character is becoming a character everytime we add a bit
int	main(void)
{
	pid_t				my_pid_bonus;
	struct sigaction	sa_newsig;

	my_pid_bonus = getpid();
	ft_printf("Bonus Server PID = %d\n", (int)my_pid_bonus);
	sa_newsig.sa_flags = SA_SIGINFO;
	sa_newsig.sa_sigaction = &new_action_to_sig;
	sigaction(SIGUSR1, &sa_newsig, NULL);
	sigaction(SIGUSR2, &sa_newsig, NULL);
	while (1)
		pause ();
	return (0);
}

//sigaction = used to change the action taken by a process on receipt
//of a specific signal, works as a struct
//int sigaction(int signum, const struct sigaction *act, 
//struct sigaction *oldact);
//signum specifies the signal 
//sa_newsig = user defined word -> action created by sigaction
//SA_SIGINFO = the signal handler will receive 3 args instead of 1, also
//works as a struct
//sa_flags = special flags to affect funcion of signal (int)
