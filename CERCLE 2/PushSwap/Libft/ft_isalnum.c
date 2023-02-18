/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 05:14:32 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:14:37 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return positif si C correspond à un caractère alphanumérique, sinon 0

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
