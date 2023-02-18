/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:54:43 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/28 02:54:43 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Return l'index du début de TO_FIND + 1 si il est trouvé dans STR, sinon 0

#include "libft.h"

int	ft_strchr(char *str, const char *to_find)
{
	int	i;
	int	j;
	int	reset;

	i = -1;
	if (!to_find || !to_find[0])
		return (0);
	while (str[++i])
	{
		j = 0;
		reset = 0;
		while (str[i] && to_find[j] && str[i] == to_find[j])
		{
			reset++;
			i++;
			j++;
		}
		if (!to_find[j])
			return (i - reset + 1);
		if (!str[i])
			return (0);
		i -= reset;
	}
	return (0);
}
