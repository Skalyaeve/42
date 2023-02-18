/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 20:49:03 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/01 06:48:32 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	swap(t_stack *stack, t_stack *start, int *count)
{
	int		temp;
	t_stack	*next;

	next = stack->next;
	if (!next)
		next = start;
	temp = stack->nb;
	stack->nb = next->nb;
	next->nb = temp;
	temp = stack->index;
	stack->index = next->index;
	next->index = temp;
	temp = stack->mark;
	stack->mark = next->mark;
	next->mark = temp;
	if (count)
		(*count)++;
	return (1);
}

int	push_to_b(t_stack **a, t_data *data)
{
	if (!data->b)
	{
		if (!add_member(&data->b))
			return (0);
	}
	else
	{
		data->b->prev = malloc(sizeof(t_stack));
		if (!data->b->prev)
			return (0);
		data->b->prev->next = data->b;
		data->b->prev->prev = NULL;
		data->b = data->b->prev;
	}
	data->b->nb = (*a)->nb;
	data->b->index = (*a)->index;
	data->b->mark = (*a)->mark;
	del_member(a, data->a_start);
	if (data->apply)
		ft_putstr_fd("pb\n", 1);
	return (1);
}

int	push_to_a(t_stack **a, t_data *data)
{
	(*a)->prev = malloc(sizeof(t_stack));
	if (!(*a)->prev)
		return (0);
	(*a)->prev->next = *a;
	(*a)->prev->prev = NULL;
	*a = (*a)->prev;
	(*a)->nb = data->b->nb;
	(*a)->index = data->b->index;
	(*a)->mark = data->b->mark;
	del_member(&data->b, data->b_start);
	if (data->apply)
		ft_putstr_fd("pa\n", 1);
	return (1);
}
