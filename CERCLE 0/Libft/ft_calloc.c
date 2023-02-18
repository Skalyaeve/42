/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <anguinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:00:37 by anguinau          #+#    #+#             */
/*   Updated: 2020/11/21 20:04:18 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	total_mem;
	char	*fill;

	total_mem = nmemb * size;
	if (!(p = malloc(total_mem)))
		return (NULL);
	fill = p;
	while (total_mem--)
		*fill++ = 0x0;
	return (p);
}
