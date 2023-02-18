/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:53:00 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/12 19:23:02 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return la bonne value

#include "libft.h"

int	return_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	return_min(int n1, int n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}
