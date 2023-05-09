/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:14 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/09 16:03:55 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	chartosig(char character, int bonus_server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((character & (0b1 << bit)) == 0)
			kill(bonus_server_pid, SIGUSR2);
		else
			kill(bonus_server_pid, SIGUSR1);
		bit++;
		usleep(200);
	}
}
//line 22 0b1 == 00000001

static void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("%s", "msg received\n");
		exit(0);
	}
}

t_Bool	bonus_input_checker(int argc, char **argv)
{
	int	bonus_result;

	bonus_result = 0;
	if (argc != 3)
		ft_printf("Wrong input: <./client_bonus> <PID> <Message>\n");
	else if (!ft_isstringdigit(argv[1]))
		ft_printf("Wrong PID\n");
	else if (*argv[2] == 0)
		ft_printf("empty message");
	else
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	char	*msg;
	int		bonus_server_pid;
	int		i;

	if (bonus_input_checker(argc, argv) == true)
	{
		signal(SIGUSR1, handler);
		bonus_server_pid = ft_atoi(argv[1]);
		msg = ft_strjoin(argv[2], "\n");
		i = 0;
		while (msg[i])
		{
			chartosig(msg[i], bonus_server_pid);
			i++;
		}
		chartosig('\0', bonus_server_pid);
		return (0);
	}
}

//line 65 function handler is where the "message reveived" message is 
//sent to client
//line 69 while msg sent 
//line 71 chartosig, function to transmit a message bit by bit
//line 74 we add the EOL 
