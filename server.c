/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:20:51 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/05 18:13:45 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_msg(int signal)
{
	static int	bit;
	static int	character;

	if (signal == SIGUSR1)
//	{
		character += 1 << (7 - bit);
//	ft_printf("bit = %d\n", bit); //
//	ft_printf("character = %d\n", character);//
//	ft_printf("1");
//	}
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(character, 1);
		bit = 0;
		character = 0;
	}
//	if (signal == SIGUSR2)
//		ft_printf("0");
}

// line 20 if we reveive the SIGUSR1 msg
// line 21 we put in the varaible character bit by bit for the 
// first character of the message
// line 24 we increment till there's the 8 bit
// line 27 once it's done we print the character and 
// reset the bit counter and the character
// if it'a 1, it's writen by sig1 if it's 0 sig2
int	main(void)
{
	pid_t	my_pid;

	my_pid = getpid();
	ft_printf("Server PID = %d\n", (int)my_pid);
	signal(SIGUSR1, print_msg);
	signal(SIGUSR2, print_msg);
	while (1)
		sleep (5);
	return (0);
}

/*pid_t = variable of process identification. Is an (int)
getpid() = function to return the process id
getppid() = function to return the parent process id\
sleep() = function for waiting a thread for a specific time (sec)
thread = (fil d'execution). For example, if you are doing 
a big operation with a program like a render video, threads
allows you to continue to interact with the program while
the render is continuing
fork system call = is used to create a new process, child processe
wait system call = blocks the calling process until one of the child
process exits or a signal is reveived. after the child process is terminated,
parent continues*/

//signal = software generated interrupt sent to a process by the OS 
//using ctrl+c for example
//sigemptyset = initialize a signal mask to exclude all signals
//sigaddset = add a signal to the signal mask
//
//pause = function to wait until a signal arrives
//passed to it
//global variable = variable that could be present in every part of the program
//not necessary to use it in a parameter of a function
//SIGUSR1 = user defined signal 1. By default terminate process
//SIGUSR2 = user defined signal 2. By default terminate process
//
//line 50, a sleep function is used because if there is only the while(1) loop
//the program doesn't have the time to reveive the message
