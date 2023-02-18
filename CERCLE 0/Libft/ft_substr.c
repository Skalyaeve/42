/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:18:17 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/21 20:08:38 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	char	*send;

	i = 0;
	while (s && s[i])
		i++;
	if (i < start)
	{
		if (!s || !(str = malloc(1)))
			return (NULL);
		*str = '\0';
		return (str);
	}
	i = 0;
	while (s && s[start++] && len--)
		i++;
	if (!s || !(str = malloc(i + 1)))
		return (NULL);
	send = str;
	start -= i + 1;
	while (s[start] && i--)
		*str++ = s[start++];
	*str = '\0';
	return (send);
}
