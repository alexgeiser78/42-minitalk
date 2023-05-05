/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:21:08 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/05 17:03:25 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int server_pid, char msg)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((msg >> bit & 1) == 0)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(400); // check value
		bit--;
	}
}
//binary
// & = AND, takes 2 numbers as operand and compare them,
// if the binary finishes by 1 the answer is 1
// | = OR, takes 2 numbers os operand and compare them, if one of them is 1
// it's a an addition of all 1
// ^ = XOR result is 1 if the two bits are different
// << = left shift, takes 2 numbers and deplace all to the left accordint to
// the number after <<
// >> = right shift
// ~ = invert the number 8 = -9

// line 22 ex msg a : 01100001
// 	          1 : 00000001
// if the & comparaison between the first bit of a (0) 
// and the last bit of 1 (1) is wrong(0), we send thru SIGUSR2 which 
// will be interpreted by the client as a 0 if not, we send thru SIGUSR1 
// which will be a 1
// kill = command used to send simple messages to process running on 
// the system. By defalut, the message sent is the 
// termination signal(sigterm)
// 
// usleep =  suspend the current processe for the number of microseconds
// line 34 we move to the next bit of 

t_Bool	input_checker(int argc, char **argv)
{
	int	result;

	result = 0;
	if (argc != 3)
		ft_printf("Wrong input: <./client> <PID> <Message>\n");
	else if (!ft_isstringdigit(argv[1]))
		ft_printf("Wrong PID\n");
	else if (*argv[2] == 0)
		ft_printf("empty message\n");
	else
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	int		i;
	int		server_pid;
	char	*msg;

	i = 0;
	if (input_checker(argc, argv) == true)
	{
		server_pid = ft_atoi(argv[1]);
		msg = ft_strdup(argv[2]);
		while (msg[i] != '\0')
		{
			send_msg(server_pid, msg[i]);
			i++;
		}
		send_msg(server_pid, msg[i]);
		free(msg);
	}
	return (0);
}

//ligne 89 envoies le message caractere par caractere
//line 92 send the '\0' message
