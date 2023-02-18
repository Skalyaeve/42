/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:20:20 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:23:44 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Copie SIZE caractères de SRC vers DEST, puis return la size de SRC

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0x0);
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (size-- > 1 && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (i);
}
