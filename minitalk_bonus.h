/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:39:36 by ageiser           #+#    #+#             */
/*   Updated: 2023/05/09 15:50:19 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <signal.h>  // used for ginal functions
# include <unistd.h>  //used for sleep
# include <sys/signal.h> //used for pid_t

typedef enum booleen
{
	false,
	true
}t_Bool;

t_Bool	input_checker(int argc, char **argv);
void	send_msg(int server_pid, char msg);
//static void	print_msg(int signal);

#endif
