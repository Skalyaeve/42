/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_method_ter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:52:11 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:55 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_a_gap_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	data->i = *a;
	data->prev = data->i->prev;
	if (!data->prev)
		data->prev = end;
	data->offset = 1;
	if (data->prev->nb == data->a_max)
		data->offset = -data->prev->index;
	while (data->prev->index + data->offset == data->i->index)
	{
		data->i = data->prev;
		data->prev = data->i->prev;
		if (!data->prev)
			data->prev = end;
		data->offset = 1;
		if (data->prev->nb == data->a_max)
			data->offset = -data->prev->index;
	}
	closest_top_head(a, start, data);
	gap_finded_gt(data);
	closest_down_head(a, start, data);
	get_closest_gap_gt(a, start, end, data);
	return (1);
}

int	push_back_gt_bis(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	while (*a != data->a_gap_end || data->b != data->fill_gap_head)
	{
		check_a_stack(a, &start, &end, data);
		check_b_stack(*a, data);
		if (data->b == data->fill_gap_head)
		{
			data->b_rot_needed = 0;
			data->b_r_rot_needed = 0;
		}
		if (++data->ret && check_for_rotate_gt(a, start, end, data))
			continue ;
		else if (data->b_rot_needed)
			rotate(NULL, NULL, data);
		else if (data->b_r_rot_needed)
			rev_rotate(NULL, NULL, data);
	}
	return (1);
}

int	push_back_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	data->a_ready = 1;
	data->b_ready = 1;
	while (data->b)
	{
		data->stop_loop = 0;
		check_a_stack(a, &start, &end, data);
		check_b_stack(*a, data);
		get_a_gap_gt(a, start, end, data);
		data->stop_loop = 0;
		check_a_stack(a, &start, &end, data);
		check_b_stack(*a, data);
		push_back_gt_bis(a, start, end, data);
		data->offset = data->a_gap_start->nb;
		if (data->offset == data->a_max)
			data->offset = data->b->nb - 1;
		if (data->b && data->b->nb < data->a_gap_end->nb
			&& data->b->nb > data->offset)
			if (++data->ret && !push_to_a(a, data))
				return (0);
	}
	return (1);
}
