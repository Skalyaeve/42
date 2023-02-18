/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:13:16 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:40 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	b_stack_unascending_bis(t_stack *backup, t_data *data)
{
	t_stack	*next;

	data->b = data->b->prev;
	if (!data->b)
		data->b = data->b_end;
	while (data->b->nb != backup->nb)
	{
		--data->to_raw;
		next = data->b->next;
		if (!next)
			next = data->b_start;
		if (data->b->nb < next->nb && next->nb != data->b_max)
			break ;
		data->b = data->b->prev;
		if (!data->b)
			data->b = data->b_end;
	}
	return (1);
}

int	b_stack_unascending(t_data *data, t_stack *backup, t_stack *next)
{
	data->b = data->b->next;
	if (!data->b)
		data->b = data->b_start;
	while (data->b->nb != backup->nb)
	{
		next = data->b->next;
		if (!next)
			next = data->b_start;
		if (data->b->nb < next->nb && next->nb != data->b_max
			&& ++data->b_unascending)
			break ;
		++data->to_raw;
		data->b = data->b->next;
		if (!data->b)
			data->b = data->b_start;
	}
	data->b = backup;
	b_stack_unascending_bis(backup, data);
	data->b = backup;
	if (data->to_raw > 0 && ++data->b_r_rot_needed && data->b_unascending)
		return (0);
	if ((data->to_raw < 0 || (data->to_raw == 0 && data->b_unascending))
		&& ++data->b_rot_needed)
		return (0);
	return (1);
}

int	check_b_stack_ter(t_stack *a, t_stack *backup, t_data *data)
{
	t_stack	*next;
	int		offset;

	data->to_raw = 1;
	data->b_unascending = 0;
	data->b = backup;
	next = data->b->next;
	if (!next)
		next = data->b_start;
	offset = -1;
	if (a->index == 0)
		offset = data->b_max_index;
	if (data->b->index == a->index + offset && data->a_ready
		&& ++data->b_push_needed)
		return (0);
	if (data->b->nb < next->nb && (next->nb != data->b_max
			|| data->b->nb != data->b_min) && ++data->b_swap_needed)
		return (0);
	backup = data->b;
	if (!data->b_ready && !b_stack_unascending(data, backup, NULL))
		return (0);
	return (1);
}

void	check_b_stack_bis(t_data *data)
{
	while (data->b->prev)
		data->b = data->b->prev;
	data->b_start = data->b;
	while (data->b->next)
	{
		if (data->b->nb == data->fill_gap_head_nb)
			data->fill_gap_head = data->b;
		if (data->b->nb == data->b_max)
			data->b_max_index = data->b->index;
		data->b = data->b->next;
	}
	if (data->b->nb == data->fill_gap_head_nb)
		data->fill_gap_head = data->b;
	if (data->b->nb == data->b_max)
		data->b_max_index = data->b->index;
	data->b_end = data->b;
}

int	check_b_stack(t_stack *a, t_data *data)
{
	t_stack	*backup;

	data->b_swap_needed = 0;
	data->b_push_needed = 0;
	if (!data->b_ready)
	{
		data->b_rot_needed = 0;
		data->b_r_rot_needed = 0;
	}
	backup = data->b;
	if (!data->b)
		return (1);
	get_stack_min_max(&data->b, data, &data->b_min, &data->b_max);
	check_b_stack_bis(data);
	if (!check_b_stack_ter(a, backup, data))
		return (0);
	return (1);
}
