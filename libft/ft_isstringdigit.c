/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstringdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageiser <ageiser@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:19:53 by ageiser           #+#    #+#             */
/*   Updated: 2023/04/28 15:50:05 by ageiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isstringdigit(char *string)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (string[i])
	{
		if (ft_isdigitis1(string[i]) == 1)
			res = 1;
		else
			return (0);
		i++;
	}
	return (res);
}
