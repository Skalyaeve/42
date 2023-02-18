/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_method_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:18:38 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:59 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	align_b_stack_im(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	while (!check_b_stack(*a, data) && ++data->ret)
	{
		check_a_stack(a, &start, &end, data);
		if (data->b_swap_needed && swap(data->b, data->b_start, NULL)
			&& data->apply)
			ft_putstr_fd("sb\n", 1);
		else if (data->b_push_needed)
		{
			if (!push_to_a(a, data))
				return (0);
		}
		else if (data->b_rot_needed)
			rotate(NULL, NULL, data);
		else
			rev_rotate(NULL, NULL, data);
		check_a_stack(a, &start, &end, data);
	}
	return (1);
}

void	realign_im(t_stack **a, t_stack *start, t_stack *end, t_data *data)
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
}

int	a_to_head(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	check_a_stack(a, &start, &end, data);
	while ((*a) != data->head_index && ++data->ret)
	{
		check_b_stack(*a, data);
		get_to_raw(a, start, data, data->head_index->nb);
		if (data->to_raw < 0)
			rotate(a, start, data);
		else
			rev_rotate(a, end, data);
		check_a_stack(a, &start, &end, data);
	}
	data->a_ready = 1;
	if (!push_back_im(a, start, end, data))
		return (0);
	realign_im(a, start, end, data);
	return (1);
}

int	unswap_im(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	swap(*a, start, NULL);
	check_a_stack(a, &start, &end, data);
	assign_mark_im(data->head_index, start, data);
	if (!(*a)->mark)
	{
		if (!push_to_b(a, data))
			return (0);
	}
	else
		rotate(a, start, data);
	return (1);
}

int	resolve_by_index(t_stack **a, t_stack *start, t_stack *end, t_data *data)
{
	while (!check_a_stack(a, &start, &end, data))
	{
		check_b_stack(*a, data);
		swap(*a, start, &data->ret);
		check_a_stack(a, &start, &end, data);
		data->temp_mark_count = assign_mark_im(data->head_index, start, data);
		if (data->temp_mark_count <= data->mark_count)
			unswap_im(a, start, end, data);
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
		assign_mark_im(data->head_index, start, data);
	}
	return (a_to_head(a, start, end, data));
}
