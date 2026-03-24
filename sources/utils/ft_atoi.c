/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/24 16:05:38 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		if (res * sign > 2147483647 || res * sign < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return (res * sign);
}
