/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:50:07 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/21 23:02:48 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!little[j])
		return ((char *)big);
	while (big[++i] && len--)
	{
		if (big[i] == little[j])
			while (big[i] && little[j] && big[i++] == little[j++]
			&& len)
				len--;
		if (little[j] == '\0' && big[i - 1] == little[j - 1])
			return ((char *)big + i - j);
		i -= j;
		if (j)
			len += j - 1;
		j = 0;
	}
	return (NULL);
}
