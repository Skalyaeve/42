/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:18:17 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/28 05:58:26 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  Malloc un char*, y écrit LEN caractères de S à partir de START,
puis return le char* */

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
		if (!s || !malloc_str(&str, 0))
			return (NULL);
		return (str);
	}
	i = 0;
	while (s && s[start++] && len--)
		i++;
	if (!s || !malloc_str(&str, i))
		return (NULL);
	send = str;
	start -= i + 1;
	while (s[start] && i--)
		*str++ = s[start++];
	return (send);
}
