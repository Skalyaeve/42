/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_method_quint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 01:06:23 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:50 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	gap_finded_gt(t_data *data)
{
	data->stop_loop = data->moves_count;
	data->fill_gap_head_nb = data->j->nb;
	data->a_gap_start_nb = data->prev->nb;
	data->a_gap_end_nb = data->i->nb;
	data->b_rot_needed = 0;
	data->b_r_rot_needed = 0;
	if (data->b != data->j)
	{
		if (get_to_raw(&data->b, data->b_start, data, data->j->nb)
			&& data->to_raw > 0)
			++data->b_r_rot_needed;
		else
			++data->b_rot_needed;
	}
}

void	closest_top_head_bis(t_data *data)
{
	data->temp = data->j;
	data->j = data->j->prev;
	if (!data->j)
		data->j = data->b_end;
	data->index = data->j->prev;
	if (!data->index)
		data->index = data->b_end;
	while (data->j != data->temp && data->j->index < data->index->index
		&& (data->index->index < data->i->index
			&& data->index->index > data->prev->index - 1 + data->offset))
	{
		data->j = data->j->prev;
		data->index = data->j->prev;
		if (!data->index)
			data->index = data->b_end;
	}
}

void	closest_top_head(t_stack **a, t_stack *start, t_data *data)
{
	data->j = data->b;
	while (data->j->index > data->i->index
		|| data->j->index < data->prev->index - 1 + data->offset)
	{
		data->j = data->j->prev;
		if (!data->j)
			data->j = data->b_end;
	}
	data->index = data->j->prev;
	if (!data->index)
		data->index = data->b_end;
	if (data->j->index > data->index->index
		|| (data->index->index > data->i->index
			|| data->index->index < data->prev->index - 1 + data->offset))
	{
		data->moves_count = count_moves_gt(a, start, data);
		if (data->moves_count < data->stop_loop)
			gap_finded_gt(data);
	}
	else
		closest_top_head_bis(data);
}

void	closest_down_head(t_stack **a, t_stack *start, t_data *data)
{
	data->j = data->b;
	data->temp = data->j;
	while (data->j->index > data->i->index
		|| data->j->index < data->prev->index - 1 + data->offset)
	{
		data->j = data->j->next;
		if (!data->j)
			data->j = data->b_start;
	}
	if (data->j == data->temp)
		closest_top_head(a, start, data);
	else
	{
		data->moves_count = count_moves_gt(a, start, data);
		if (data->moves_count < data->stop_loop)
			gap_finded_gt(data);
	}
}

void	get_closest_gap_gt(t_stack **a, t_stack *start,
		t_stack *end, t_data *data)
{
	data->i = data->prev;
	while (data->i != *a)
	{
		data->prev = data->i->prev;
		if (!data->prev)
			data->prev = end;
		data->offset = 1;
		if (data->prev->nb == data->a_max)
			data->offset = -data->prev->index;
		if (data->prev->index + data->offset != data->i->index)
		{
			closest_top_head(a, start, data);
			closest_down_head(a, start, data);
		}
		data->i = data->prev;
	}
}
