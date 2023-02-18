/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:29:25 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/01 07:48:19 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_stack_size(t_stack *stack)
{
	int		i;
	t_stack	*index;

	i = 0;
	index = stack;
	while (index->prev)
		index = index->prev;
	while (index)
	{
		i++;
		index = index->next;
	}
	return (i);
}
