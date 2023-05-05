/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:14 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/05 17:12:18 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bonus_msg(int bonus_server_pid, char *msg)
{
	int bit;
	char character;

	while (*msg)
	{
		character = *msg;
		bit = 8;
		while (bit >= 0)
		{
			if ((character << bit & 128) == 0)
				kill(bonus_server_pid, SIGUSR2);
			else
				kill(bonus_server_pid, SIGUSR1);
			usleep(50);
			bit--;

		}
		msg++;
	}
}

t_Bool	bonus_input_checker(int argc, char **argv)
{
	int bonus_result;

	bonus_result = 0;
	if (argc != 3)
		ft_printf("Wrong input: <./client_bonus> <PID> <Message>\n");
	else if (!ft_isstringdigit(argv[1]))
		ft_printf("Wrong PID\n");
	else if(*argv[2] == 0)
		ft_printf("empty message");
	else	
		return(true);
	return (false);
}

int	main(int argc, char **argv)
{
//	int i;
	int bonus_server_pid;
	char *msg;

	if (bonus_input_checker(argc, argv) == true)
	{

		bonus_server_pid = ft_atoi(argv[1]);
		msg = ft_strjoin(argv[2], "\n");



	send_bonus_msg(bonus_server_pid, msg);
	free (msg);
	}
	while (1)
		pause();
	return (0);
}


//line 50 in this case we send the entire msg 
//and not only one char
