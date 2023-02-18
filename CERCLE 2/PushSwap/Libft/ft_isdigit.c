/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:11:06 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:32 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return positif si C correspond à un caractère numérique, sinon 0

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}
