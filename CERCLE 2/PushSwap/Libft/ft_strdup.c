/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:22:01 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/26 08:15:29 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Malloc un char*, y écrit *S, puis return le char*

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;
	char	*send;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	send = str;
	while (i--)
		*str++ = *s++;
	*str++ = *s++;
	return (send);
}
