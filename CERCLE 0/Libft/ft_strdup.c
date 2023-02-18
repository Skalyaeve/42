/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:22:01 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/25 18:17:53 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;
	char	*send;

	i = 0;
	while (s[i])
		i++;
	if (!(str = malloc(i + 1)))
		return (NULL);
	send = str;
	while (i--)
		*str++ = *s++;
	*str++ = *s++;
	return (send);
}
