/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:56:51 by anguinau          #+#    #+#             */
/*   Updated: 2022/03/03 09:01:27 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	resolve(t_stack **a, t_stack **b, int size)
{
	int	gt_method_ret;
	int	index_method_ret;

	gt_method_ret = gt_method(a, b, size, 0);
	if (gt_method_ret < 0)
		return (0);
	index_method_ret = index_method(a, b, size, 0);
	if (index_method_ret < 0)
		return (0);
	if (index_method_ret < gt_method_ret)
		index_method_ret = index_method(a, b, size, 1);
	else
		gt_method_ret = gt_method(a, b, size, 1);
	return (1);
}

int	fill_a(t_parsing *parsing, t_stack *a, int size, int i)
{
	t_stack	*start;

	while (++i < size)
	{
		parsing->nb[i + size] = 0;
		parsing->j = -1;
		while (++parsing->j < size)
			if (parsing->nb[i] > parsing->nb[parsing->j])
				parsing->nb[i + size]++;
	}
	i = -1;
	start = a;
	while (++i < size)
	{
		a->nb = (int)parsing->nb[i];
		a->index = (int)parsing->nb[i + size];
		a->mark = 0;
		if (!add_member(&a))
			return (0);
		a = a->next;
	}
	del_member(&a, start);
	while (a->prev)
		a = a->prev;
	return (1);
}

int	check_input(int ac, char **av, long long *nb)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	while (++j <= ac - 1)
	{
		while (av[j][++i])
			if (!ft_isdigit(av[j][i]) && !check_neg(av, j, i))
				return (0);
		nb[j - 1] = ft_long_long_atoi(av[j]);
		if (nb[j - 1] < -2147483648 || nb[j - 1] > 2147483647)
			return (0);
		i = -1;
	}
	while (++i < ac - 1)
	{
		k = i;
		while (++k < ac - 1)
			if (nb[i] == nb[k])
				return (0);
	}
	return (j - 2);
}

int	check_single_arg(int ac, char **av)
{
	int			i;
	long long	nb;

	i = -1;
	if (ac == 2)
	{
		while (av[1][++i])
			if (!ft_isdigit(av[1][i]) && !check_neg(av, 1, i))
				return (error(NULL, NULL, NULL));
		nb = ft_long_long_atoi(av[1]);
		if (nb < -2147483648 || nb > 2147483647)
			return (error(NULL, NULL, NULL));
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_parsing	parsing;

	if (ac > 2)
	{
		parsing.nb = malloc(sizeof(long long) * (ac - 1) * 2);
		if (!parsing.nb)
			return (error(NULL, NULL, NULL));
		a = malloc(sizeof(t_stack));
		if (!a)
			return (error(NULL, NULL, parsing.nb));
		b = NULL;
		a->prev = NULL;
		a->next = NULL;
		if (!check_input(ac, av, parsing.nb))
			return (error(&a, NULL, parsing.nb));
		if (!fill_a(&parsing, a, ac - 1, -1))
			return (error(&a, NULL, parsing.nb));
		free(parsing.nb);
		if (!resolve(&a, &b, ac - 1))
			return (error(&a, &b, NULL));
		free_stack(&a);
	}
	return (check_single_arg(ac, av));
}
