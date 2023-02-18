/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:28:20 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/09 17:30:04 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Return 1 si les n premiers char de to_find
sont dans les n premiers char de src, sinon 0 */

#include "libft.h"

int	ft_strncmp(char *src, char *to_find, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] && to_find[i] && src[i] == to_find[i])
		i++;
	if (i == n || !to_find[i])
		return (1);
	return (0);
}
