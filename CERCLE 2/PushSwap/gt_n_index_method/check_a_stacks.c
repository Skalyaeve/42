/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_a_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:44:07 by anguinau          #+#    #+#             */
/*   Updated: 2022/02/10 17:48:36 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	check_a_stack_bis(t_stack **a, t_data *data)
{
	if ((*a)->nb == data->a_gap_start_nb)
		data->a_gap_start = *a;
	if ((*a)->nb == data->a_gap_end_nb)
		data->a_gap_end = *a;
	if ((*a)->nb == data->head_index_nb)
		data->head_index = *a;
	if (!(*a)->next)
		data->stop_loop = 1;
	else
		*a = (*a)->next;
}

int	check_a_stack(t_stack **a, t_stack **start, t_stack **end, t_data *data)
{
	int		ret;
	t_stack	*backup;

	ret = 1;
	backup = *a;
	get_stack_min_max(a, data, &data->a_min, &data->a_max);
	while ((*a)->prev)
		*a = (*a)->prev;
	*start = *a;
	while (!data->stop_loop)
	{
		if (!(*a)->mark)
			ret = 0;
		check_a_stack_bis(a, data);
	}
	*end = *a;
	data->stop_loop = 0;
	*a = backup;
	return (ret);
}
