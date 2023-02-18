/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:32:58 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/01 06:48:39 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	add_member(t_stack **stack)
{
	if (!*stack)
	{
		*stack = malloc(sizeof(t_stack));
		if (!*stack)
			return (0);
		(*stack)->prev = NULL;
		(*stack)->next = NULL;
		(*stack)->nb = 0;
		(*stack)->index = -1;
		(*stack)->mark = -1;
	}
	else
	{
		(*stack)->next = malloc(sizeof(t_stack));
		if (!(*stack)->next)
			return (0);
		(*stack)->next->prev = *stack;
		(*stack)->next->next = NULL;
		(*stack)->next->nb = 0;
		(*stack)->next->index = -1;
		(*stack)->next->mark = -1;
	}
	return (1);
}

int	del_member(t_stack **stack, t_stack *start)
{
	t_stack	*prev;

	if (!(*stack)->next && (*stack)->prev)
	{
		(*stack)->prev->next = NULL;
		free(*stack);
		*stack = start;
	}
	else if ((*stack)->next)
	{
		prev = (*stack)->prev;
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = prev;
		if (prev)
			(*stack)->prev->next = *stack;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
	return (1);
}

int	free_stack(t_stack **stack)
{
	if (stack && *stack)
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		while ((*stack)->next)
		{
			*stack = (*stack)->next;
			free((*stack)->prev);
			(*stack)->prev = NULL;
		}
		free(*stack);
		*stack = NULL;
	}
	return (1);
}

int	get_stack_min_max(t_stack **stack, t_data *data, int *min, int *max)
{
	t_stack	*backup;

	backup = *stack;
	while ((*stack)->prev)
		*stack = (*stack)->prev;
	*min = (*stack)->nb;
	*max = (*stack)->nb;
	while (!data->stop_loop)
	{
		if ((*stack)->nb < *min)
			*min = (*stack)->nb;
		if ((*stack)->nb > *max)
			*max = (*stack)->nb;
		if (!(*stack)->next)
			data->stop_loop = 1;
		else
			*stack = (*stack)->next;
	}
	data->stop_loop = 0;
	*stack = backup;
	return (1);
}

int	get_to_raw(t_stack **stack, t_stack *start, t_data *data, int target)
{
	t_stack	*backup;

	backup = *stack;
	data->to_raw = 0;
	while ((*stack)->nb != target)
	{
		*stack = (*stack)->next;
		if (!*stack)
			*stack = start;
		++data->to_raw;
	}
	*stack = backup;
	while ((*stack)->nb != target)
	{
		*stack = (*stack)->prev;
		if (!*stack)
		{
			*stack = backup;
			while ((*stack)->next)
				*stack = (*stack)->next;
		}
		--data->to_raw;
	}
	*stack = backup;
	return (1);
}
