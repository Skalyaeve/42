/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:30:17 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:42 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return 1 si C correspond à un caractère affichable, sinon 0

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}
