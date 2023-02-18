/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_method_ter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:50:13 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:49:02 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	get_target_im(t_stack **a, t_data *data, int offset)
{
	t_stack	*backup;
	int		ret;

	backup = data->b;
	while (data->b->index != (*a)->index + offset)
	{
		data->b = data->b->next;
		if (!data->b)
			data->b = data->b_start;
	}
	ret = data->b->nb;
	data->b = backup;
	return (ret);
}

int	push_back_im(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	int	offset;

	while (data->b && ++data->ret)
	{
		check_a_stack(a, &start, &end, data);
		check_b_stack(*a, data);
		offset = -1;
		if ((*a)->index == 0)
			offset = data->b_max_index;
		if ((*a)->index + offset == data->b->index)
		{
			if (!push_to_a(a, data))
				return (0);
		}
		else
		{
			get_to_raw(&data->b, data->b_start, data,
				get_target_im(a, data, offset));
			if (data->to_raw < 0 && ++data->b_rot_needed)
				rotate(NULL, NULL, data);
			else if (++data->b_r_rot_needed)
				rev_rotate(NULL, NULL, data);
		}
	}
	return (1);
}
