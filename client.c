/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:21:08 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/25 16:46:15 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_Bool input_checker(int argc, char **argv)
{
	int result;

	result = 0;
	if(argc != 3)
		ft_printf("wrong input: ./client PID Message\n");
	else if (!ft_isdigit(argv[1]))
		ft_printf("wrong PID\n");
	else if (*argv[2] == 0) // null plutot, non?
		ft_printf("empty message\n");
	else
		return(true);
	return(false);
}

int main(int argc, char **argv)
{
	int i;
	int server_pid;
	char *msg;
	
	i = 0;

	if(input_checker(argc, argv) == true)
	{
		server_pid = ft_atoi(argv[1]);
		msg = ft_strdup(argv[2]);
		while (msg[i] != '\0')
		{
			send_msg(server_pid, msg[i]);
			i++;
		}
	free(msg);
	send_msg(server_pid, '\n');
	}
	return(0);
}
				
				
				
				}
	}


return(0);
}
