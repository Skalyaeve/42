/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:11:39 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/01 07:08:04 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	assign_values(t_stack *src, t_stack *dest)
{
	dest->nb = src->nb;
	dest->index = src->index;
	dest->mark = src->mark;
}

void	rev_rotate_bis(t_stack **a, int target)
{
	t_stack	*index;
	t_stack	*index_next;
	t_stack	temp;
	t_stack	temp_bis;

	index = *a;
	assign_values(*a, &temp);
	while ((*a)->nb != target)
	{
		index_next = index->next;
		if (!index_next)
		{
			index_next = index;
			while (index_next->prev)
				index_next = index_next->prev;
		}
		assign_values(index_next, &temp_bis);
		assign_values(&temp, index_next);
		assign_values(&temp_bis, &temp);
		index = index_next;
	}
}

void	rev_rotate(t_stack **a, t_stack *end, t_data *data)
{
	t_stack	*prev;

	if (a && *a)
	{
		prev = (*a)->prev;
		if (!prev)
			prev = end;
		rev_rotate_bis(a, prev->nb);
	}
	if (data->b && data->b_r_rot_needed)
	{
		prev = data->b->prev;
		if (!prev)
			prev = data->b_end;
		rev_rotate_bis(&data->b, prev->nb);
	}
	if (data->b && data->b_r_rot_needed && a && *a && data->apply)
		ft_putstr_fd("rrr\n", 1);
	else if (data->b && data->b_r_rot_needed && data->apply)
		ft_putstr_fd("rrb\n", 1);
	else if (data->apply)
		ft_putstr_fd("rra\n", 1);
}

void	rotate_bis(t_stack **a, int target)
{
	t_stack	*index;
	t_stack	*index_prev;
	t_stack	temp;
	t_stack	temp_bis;

	index = *a;
	assign_values(*a, &temp);
	while ((*a)->nb != target)
	{
		index_prev = index->prev;
		if (!index_prev)
		{
			index_prev = index;
			while (index_prev->next)
				index_prev = index_prev->next;
		}
		assign_values(index_prev, &temp_bis);
		assign_values(&temp, index_prev);
		assign_values(&temp_bis, &temp);
		index = index_prev;
	}
}

void	rotate(t_stack **a, t_stack *start, t_data *data)
{
	t_stack	*next;

	if (a && *a)
	{
		next = (*a)->next;
		if (!next)
			next = start;
		rotate_bis(a, next->nb);
	}
	if (data->b && data->b_rot_needed)
	{
		next = data->b->next;
		if (!next)
			next = data->b_start;
		rotate_bis(&data->b, next->nb);
	}
	if (data->b && data->b_rot_needed && a && *a && data->apply)
		ft_putstr_fd("rr\n", 1);
	else if (data->b && data->b_rot_needed && data->apply)
		ft_putstr_fd("rb\n", 1);
	else if (data->apply)
		ft_putstr_fd("ra\n", 1);
}
