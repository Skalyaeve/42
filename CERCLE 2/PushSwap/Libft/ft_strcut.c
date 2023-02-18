/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 03:37:24 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/28 03:37:24 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Malloc un char*, y écrit SRC de START inclus à STOP exclus

#include "libft.h"

char	*ft_strcut(const char *src, int start, const char stop)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[start + i] && src[start + i] != stop)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	dest[i] = '\0';
	i = 0;
	while (src[start + i] && src[start + i] != stop)
	{
		dest[i] = src[start + i];
		i++;
	}
	return (dest);
}
