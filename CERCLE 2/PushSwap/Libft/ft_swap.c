/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:47:51 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/01 07:50:32 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Echange les valeurs int de ptr1 et ptr2

#include "libft.h"

int	ft_swap(int *ptr1, int *ptr2)
{
	int	temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
	return (1);
}
