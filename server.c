/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:20:51 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/25 13:34:31 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	pid_t	my_PID;


	my_PID = getpid();
	ft_printf("Server PID = %d\n", (int)my_PID);

	while(1)
		sleep(5);
	return(0);
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
//sigaction = used to chande the action taken by a process on receipt
//of a specific signal
//kill = command used to send simple messages to process running on 
//the system. By defalut, the message sent is the 
//termination signal(sigterm)
//pause = function to wait until a signal arrives
//usleep =  suspend the current processe for the number of microseconds
//passed to it
//global variable = variable that could be present in every part of the program
//not necessary to use it in a parameter of a function
//SIGUSR1 = user defined signal 1. By default terminate process
//SIGUSR2 = user defined signal 2. By default terminate process
