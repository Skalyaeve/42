/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:21:04 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/23 17:55:20 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

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

int	ft_strchr(char *str, const char *to_find)
{
	int	i;
	int	j;
	int	reset;

	i = -1;
	while (str[++i])
	{
		j = 0;
		reset = 0;
		while (str[i] && to_find[j] && str[i] == to_find[j])
		{
			reset++;
			i++;
			j++;
		}
		if (!to_find[j])
			return (i - reset);
		if (!str[i])
			return (-1);
		i -= reset;
	}
	return (-1);
}
