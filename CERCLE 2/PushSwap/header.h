/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 01:50:34 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/03 09:00:04 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HEADER_H
# define HEADER_H

# include "Libft/libft.h"

typedef struct s_parsing
{
	long long	*nb;
	int			j;
}				t_parsing;

typedef struct s_stack
{
	int				nb;
	int				index;
	int				mark;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_chunk
{
	int				end_index;
	struct s_chunk	*next;
	struct s_chunk	*prev;
}					t_chunk;

typedef struct s_data
{
	int		size;
	int		ret;
	int		temp_mark_count;
	int		mark_count;
	int		stop_loop;
	int		a_min;
	int		a_max;
	int		b_min;
	int		b_max;
	int		b_swap_needed;
	int		b_push_needed;
	int		b_rot_needed;
	int		b_r_rot_needed;
	int		a_swap_needed;
	int		a_push_needed;
	int		a_rot_needed;
	int		a_r_rot_needed;
	int		to_raw;
	int		a_ready;
	int		b_ready;
	int		b_unascending;
	int		head_index_nb;
	int		a_gap_start_nb;
	int		a_gap_end_nb;
	int		fill_gap_head_nb;
	int		b_max_index;
	int		moves_count;
	int		offset;
	int		up;
	int		down;
	int		apply;
	int		rot;
	t_stack	*a;
	t_stack	*fake_a;
	t_stack	*b;
	t_stack	*a_gap_start;
	t_stack	*a_gap_end;
	t_stack	*fill_gap_head;
	t_stack	*a_start;
	t_stack	*fake_a_start;
	t_stack	*b_start;
	t_stack	*a_end;
	t_stack	*fake_a_end;
	t_stack	*b_end;
	t_stack	*head_index;
	t_stack	*i;
	t_stack	*j;
	t_stack	*prev;
	t_stack	*next;
	t_stack	*end;
	t_stack	*temp;
	t_stack	*index;
}			t_data;

int		add_member(t_stack **stack);
int		del_member(t_stack **stack, t_stack *start);
int		free_stack(t_stack **stack);
int		get_stack_min_max(t_stack **stack, t_data *data, int *min, int *max);
int		get_to_raw(t_stack **stack, t_stack *start,
			t_data *data, int target);
int		swap(t_stack *stack, t_stack *start, int *count);
int		push_to_b(t_stack **a, t_data *data);
int		push_to_a(t_stack **a, t_data *data);
void	rev_rotate(t_stack **a, t_stack *end, t_data *data);
void	rotate(t_stack **a, t_stack *start, t_data *data);
int		check_a_stack(t_stack **a, t_stack **start, t_stack **end,
			t_data *data);
int		check_b_stack(t_stack *a, t_data *data);
int		index_method(t_stack **a, t_stack **b, int size, int apply);
int		gt_method(t_stack **a, t_stack **b, int size, int apply);
int		assign_mark_im(t_stack *a, t_stack *start, t_data *data);
int		assign_mark_gt(t_stack *a, t_stack *start, t_data *data);
int		resolve_by_index(t_stack **a, t_stack *start, t_stack *end,
			t_data *data);
int		resolve_by_gt(t_stack **a, t_stack *start, t_stack *end,
			t_data *data);
int		push_back_im(t_stack **a, t_stack *start, t_stack *end,
			t_data *data);
int		push_back_gt(t_stack **a, t_stack *start, t_stack *end,
			t_data *data);
int		check_for_rotate_gt(t_stack **a, t_stack *start,
			t_stack *end, t_data *data);
int		realign_gt(t_stack **a, t_stack *start, t_stack *end, t_data *data);
int		count_moves_gt(t_stack **a, t_stack *start, t_data *data);
void	get_closest_gap_gt(t_stack **a, t_stack *start,
			t_stack *end, t_data *data);
void	gap_finded_gt(t_data *data);
void	closest_top_head(t_stack **a, t_stack *start, t_data *data);
void	closest_down_head(t_stack **a, t_stack *start, t_data *data);
int		error(t_stack **a, t_stack **b, long long *nb);
int		check_neg(char **av, int j, int i);
int		get_stack_size(t_stack *stack);

#	endif
