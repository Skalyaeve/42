/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_long_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:56:48 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:15:17 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return un long long à partir d'un char* spécifique

#include "libft.h"

long long	ft_long_long_atoi(const char *nptr)
{
	long long	nbr;
	int			neg;

	nbr = 0;
	neg = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\v' || *nptr == '\f')
		nptr += 1;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			neg = -neg;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr *= 10;
		nbr += (int)*nptr - 48;
		nptr += 1;
	}
	return (nbr * neg);
}
