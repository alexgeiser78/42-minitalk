/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:25:32 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/25 17:02:37 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>  // used for ginal functions
#include <unistd.h>  //used for sleep
#include <sys/signal.h> //used for pid_t

typedef enum booleen
{
	false,
	true
}t_Bool

t_Bool input_checker(int argc, char **argv);
#endif
