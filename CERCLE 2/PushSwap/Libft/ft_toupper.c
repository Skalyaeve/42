/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:34:52 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:09 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return la valeur lowercase d'un caractère uppercase

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
