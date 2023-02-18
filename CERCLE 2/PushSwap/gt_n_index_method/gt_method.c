/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_method.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:29:44 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:57 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	prepare_fake_a_gt(t_data *data)
{
	data->fake_a = malloc(sizeof(t_stack));
	if (!data->fake_a)
		return (0);
	data->fake_a_start = data->fake_a;
	data->fake_a->prev = NULL;
	data->fake_a->next = NULL;
	while (!data->stop_loop)
	{
		data->fake_a->nb = data->a->nb;
		data->fake_a->index = data->a->index;
		data->fake_a->mark = data->a->mark;
		if (data->a->next)
			if (!add_member(&data->fake_a) && free_stack(&data->fake_a))
				return (0);
		data->fake_a = data->fake_a->next;
		if (!data->a->next)
			data->stop_loop = 1;
		else
			data->a = data->a->next;
	}
	data->fake_a_end = data->fake_a;
	data->stop_loop = 0;
	data->a = data->a_start;
	data->fake_a = data->fake_a_start;
	return (1);
}

int	assign_mark_gt(t_stack *a, t_stack *start, t_data *data)
{
	int	nb;

	a->mark = 1;
	nb = a->nb;
	data->temp_mark_count = 1;
	data->i = a;
	a = a->next;
	if (!a)
		a = start;
	while (a->nb != data->i->nb)
	{
		if (nb < a->nb && ++data->temp_mark_count)
			a->mark = 1;
		else
			a->mark = 0;
		if (nb < a->nb)
			nb = a->nb;
		a = a->next;
		if (!a)
			a = start;
	}
	return (1);
}

void	mark_for_push_gt(t_data *data)
{
	while (!data->stop_loop)
	{
		assign_mark_gt(data->a, data->a_start, data);
		if (data->temp_mark_count >= data->mark_count)
		{
			data->mark_count = data->temp_mark_count;
			if (data->temp_mark_count > data->mark_count)
				data->head_index = data->a;
			if (data->temp_mark_count == data->mark_count
				&& (data->head_index->index > data->a->index))
				data->head_index = data->a;
			data->head_index_nb = data->head_index->nb;
		}
		if (!data->a->next)
			data->stop_loop = 1;
		else
			data->a = data->a->next;
	}
	data->a_end = data->a;
	data->stop_loop = 0;
	assign_mark_gt(data->head_index, data->a_start, data);
	data->a = data->a_start;
}

void	fill_values_gt(t_stack *a, t_stack *b, int size, t_data *data)
{
	data->size = size;
	data->a = a;
	data->b = b;
	data->ret = 0;
	data->stop_loop = 0;
	data->mark_count = 1;
	data->head_index = data->a;
	data->head_index_nb = data->a->nb;
	data->a_min = a->nb;
	data->a_max = a->nb;
	data->a_start = a;
	data->b_start = b;
	data->b_end = b;
	data->a_ready = 0;
	data->b_ready = 0;
}

int	gt_method(t_stack **a, t_stack **b, int size, int apply)
{
	t_data	data;

	fill_values_gt(*a, *b, size, &data);
	get_stack_min_max(a, &data, &data.a_min, &data.a_max);
	*a = data.a_start;
	data.apply = apply;
	mark_for_push_gt(&data);
	if (apply)
		if (!resolve_by_gt(a, data.a_start, data.a_end, &data))
			return (-1);
	if (!apply && !prepare_fake_a_gt(&data))
		return (-1);
	if (!apply)
		if (!resolve_by_gt(&data.fake_a, data.fake_a_start,
				data.fake_a_end, &data) && free_stack(&data.fake_a))
			return (-1);
	if (!apply)
		free_stack(&data.fake_a);
	return (data.ret);
}
