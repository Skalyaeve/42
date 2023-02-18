/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 23:17:21 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/24 21:22:33 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	state1(t_philo *philo)
{
	int	ret;

	philo->dying++;
	if (philo->dying >= philo->tt_die)
		return (print_pls(philo->ms, philo->index, "died"));
	ret = taking_forks(philo, 0);
	if (!ret)
		return (0);
	if (ret == 1 && philo->nbr_of_philo > 1)
	{
		philo->state = 2;
		return (print_pls(philo->ms, philo->index, "has taken a fork"));
	}
	return (1);
}

int	state2(t_philo *philo)
{
	philo->dying++;
	if (philo->dying >= philo->tt_die)
		return (print_pls(philo->ms, philo->index, "died"));
	philo->dying = 0;
	philo->state = 3;
	return (print_pls(philo->ms, philo->index, "is eating"));
}

int	state3(t_philo *philo)
{
	philo->dying++;
	if (philo->dying >= philo->tt_die)
		return (print_pls(philo->ms, philo->index, "died"));
	philo->eating++;
	if (philo->eating >= philo->tt_eat)
	{
		philo->eating = 0;
		philo->state = 4;
		philo->meals_ate++;
		if (philo->meals_to_eat != -1
			&& philo->meals_ate == philo->meals_to_eat)
		{
			if (pthread_mutex_lock(&(data())->end_mutex))
				return (0);
			(data())->someone_finished++;
			if (pthread_mutex_unlock(&(data())->end_mutex))
				return (0);
		}
		if (!droping_forks(philo))
			return (0);
		return (print_pls(philo->ms, philo->index, "is sleeping"));
	}
	return (1);
}

int	state4(t_philo *philo)
{
	philo->dying++;
	if (philo->dying >= philo->tt_die)
		return (print_pls(philo->ms, philo->index, "died"));
	philo->sleeping++;
	if (philo->sleeping >= philo->tt_sleep)
	{
		philo->sleeping = 0;
		philo->state = 1;
		return (print_pls(philo->ms, philo->index, "is thinking"));
	}
	return (1);
}
