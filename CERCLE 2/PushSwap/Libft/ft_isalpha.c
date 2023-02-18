/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 04:58:26 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:35 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return positif si C correspond à un caractère alphabétique, sinon 0

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
