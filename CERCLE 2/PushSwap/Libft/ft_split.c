/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:28:22 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/28 05:31:46 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Malloc un char**, y écrit S en séparent les phrases par C,
puis return le char** */

#include "libft.h"

static int	count_w(char const *s, char c)
{
	int	count;

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

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		start;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	count = count_w(s, c);
	if (!malloc_str_tab(&str, count))
		return (NULL);
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
