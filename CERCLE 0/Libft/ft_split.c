/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:28:22 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/22 20:14:55 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (*s && *s != c)
			++count;
		while (*s && *s != c)
			++s;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		start;
	int		i;
	int		j;

	if ((i = 0) == 0 && !s)
		return (NULL);
	count = count_w(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	str[count] = NULL;
	j = 0;
	while (i < count)
	{
		while (s[j] && s[j] == c)
			++j;
		start = j;
		while (s[j] && s[j] != c)
			++j;
		str[i++] = ft_substr(s, start, j - start);
		if (!(str[i - 1]))
			return (NULL);
	}
	return (str);
}
