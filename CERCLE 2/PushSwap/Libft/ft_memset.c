/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:45:57 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 15:21:10 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Remplis N octets de S par C, puis return S

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n--)
		*str++ = c;
	return (s);
}
