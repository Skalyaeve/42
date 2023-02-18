/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_method_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 03:24:13 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:52 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_for_rotate_bis(t_stack **a, t_stack *start,
	t_stack *end, t_data *data)
{
	if (!data->a_ready)
	{
		if (data->stop_loop > 0 && data->b_r_rot_needed)
			rev_rotate(a, end, data);
		else if ((data->stop_loop < 0 || (*a)->nb != data->a_gap_end->nb)
			&& data->b_rot_needed)
			rotate(a, start, data);
		else
			data->stop_loop = 0;
	}
	else
	{
		if (data->stop_loop > 0)
			rev_rotate(a, end, data);
		else if (data->stop_loop < 0 || (*a)->nb != data->a_gap_end->nb)
			rotate(a, start, data);
		else
			data->stop_loop = 0;
	}
}

int	check_for_rotate_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	data->i = *a;
	if ((*a)->nb != data->a_gap_end->nb)
	{
		while (data->i->nb != data->a_gap_end->nb && --data->stop_loop)
		{
			data->i = data->i->prev;
			if (!data->i)
				data->i = end;
		}
		data->i = *a;
		while (data->i->nb != data->a_gap_end->nb)
		{
			++data->stop_loop;
			data->i = data->i->next;
			if (!data->i)
				data->i = start;
		}
	}
	check_for_rotate_bis(a, start, end, data);
	return (data->stop_loop);
}
