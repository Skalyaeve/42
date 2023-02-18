/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:51:10 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/03 09:12:49 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	error(t_stack **a, t_stack **b, long long *nb)
{
	ft_putstr_fd("Error\n", 2);
	if (a)
		free_stack(a);
	if (b)
		free_stack(a);
	if (nb)
		free(nb);
	return (-1);
}

int	check_neg(char **av, int j, int i)
{
	if (av[j][i] == '-')
	{
		if (i != 0)
			return (0);
		if (!av[j][i + 1])
			return (0);
		return (1);
	}
	return (0);
}
