/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:44:40 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:00 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return la valeur uppercase d'un caractère lowercase

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
