/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 04:41:47 by anguinau          #+#    #+#             */
/*   Updated: 2022/01/28 04:41:47 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Malloc STR de sizeof(char) * size + 1

#include "libft.h"

int	malloc_str(char **str, int size)
{
	*str = malloc(sizeof(char) * size + 1);
	if (!*str)
		return (0);
	(*str)[size] = '\0';
	return (1);
}

int	malloc_str_tab(char ***str, int size)
{
	*str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!*str)
		return (0);
	(*str)[size] = NULL;
	return (1);
}
