/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:17:54 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/22 00:17:27 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	neg;

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
