/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_method_quat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:57:47 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:47 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	realign_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	check_a_stack(a, &start, &end, data);
	check_b_stack(*a, data);
	while ((*a)->nb != data->a_min && ++data->ret)
	{
		get_to_raw(a, start, data, data->a_min);
		if (data->to_raw < 0)
			rotate(a, start, data);
		else
			rev_rotate(a, end, data);
		check_a_stack(a, &start, &end, data);
	}
	return (1);
}

int	count_moves_gt_ter(t_stack **a, t_data *data, int target)
{
	int	count;

	count = 0;
	data->temp = *a;
	while (data->temp->nb != target && --count)
	{
		data->temp = data->temp->prev;
		if (!data->temp)
		{
			data->temp = *a;
			while (data->temp->next)
				data->temp = data->temp->next;
		}
	}
	return (count);
}

int	count_moves_gt_bis(t_stack **a, t_stack *start, t_data *data, int target)
{
	int	count;

	count = 0;
	if (get_to_raw(a, start, data, target) < 0)
	{
		data->temp = *a;
		while (data->temp->nb != target && ++count)
		{
			data->temp = data->temp->next;
			if (!data->temp)
				data->temp = start;
		}
	}
	else
		count += count_moves_gt_ter(a, data, target);
	return (count);
}

int	return_count_moves_gt(int a_count, int b_count)
{
	if (a_count < 0)
	{
		if (b_count < 0 && b_count < a_count)
			return (-b_count);
		if (b_count < 0 && b_count > a_count)
			return (-a_count);
		if (b_count >= 0)
			return (-a_count + b_count);
	}
	else if (a_count > 0)
	{
		if (b_count > 0 && b_count > a_count)
			return (b_count);
		if (b_count > 0 && b_count < a_count)
			return (a_count);
		if (b_count <= 0)
			return (a_count + (b_count * -1));
	}
	if (b_count < 0)
		return (-b_count);
	if (b_count > 0)
		return (b_count);
	return (0);
}

int	count_moves_gt(t_stack **a, t_stack *start, t_data *data)
{
	int	a_count;
	int	b_count;

	if (!data->j)
		data->j = data->b_start;
	a_count = count_moves_gt_bis(a, start, data, data->i->nb);
	b_count = count_moves_gt_bis(&data->b, data->b_start, data, data->j->nb);
	return (return_count_moves_gt(a_count, b_count));
}
