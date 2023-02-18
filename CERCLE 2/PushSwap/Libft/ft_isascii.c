/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:20:11 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:40 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return 1 si C correspond à un caractère ASCII, sinon 0

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
