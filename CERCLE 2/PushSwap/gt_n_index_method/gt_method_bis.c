/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_method_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 04:45:00 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:45 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	perform_rotate_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	while (data->temp != *a && data->temp->mark && ++data->to_raw)
	{
		data->temp = data->temp->next;
		if (!data->temp)
			data->temp = start;
	}
	data->temp = *a;
	data->temp = data->temp->prev;
	if (!data->temp)
		data->temp = end;
	--data->to_raw;
	while (data->temp != *a && data->temp->mark)
	{
		--data->to_raw;
		data->temp = data->temp->prev;
		if (!data->temp)
			data->temp = end;
	}
	if (data->temp == *a)
		return (1);
	else if (data->to_raw < 0)
		rotate(a, start, data);
	else
		rev_rotate(a, end, data);
	return (1);
}

int	unswap_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	swap(*a, start, NULL);
	check_a_stack(a, &start, &end, data);
	assign_mark_gt(data->head_index, start, data);
	if (!(*a)->mark)
	{
		if (!push_to_b(a, data))
			return (0);
	}
	else
	{
		data->to_raw = 0;
		data->temp = *a;
		data->temp = data->temp->next;
		if (++data->to_raw && !data->temp)
			data->temp = start;
		perform_rotate_gt(a, start, end, data);
	}
	return (1);
}

int	resolve_by_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	while (!check_a_stack(a, &start, &end, data))
	{
		check_b_stack(*a, data);
		swap(*a, start, &data->ret);
		check_a_stack(a, &start, &end, data);
		assign_mark_gt(data->head_index, start, data);
		if (data->temp_mark_count <= data->mark_count)
			unswap_gt(a, start, end, data);
		else
		{
			data->mark_count = data->temp_mark_count;
			if (data->b_swap_needed && swap(data->b, data->b_start, NULL)
				&& data->apply)
				ft_putstr_fd("ss\n", 1);
			else if (data->apply)
				ft_putstr_fd("sa\n", 1);
		}
		check_a_stack(a, &start, &end, data);
		assign_mark_gt(data->head_index, start, data);
	}
	if (!push_back_gt(a, start, end, data))
		return (0);
	return (realign_gt(a, start, end, data));
}
