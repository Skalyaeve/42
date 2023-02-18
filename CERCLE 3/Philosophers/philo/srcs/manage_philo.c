/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:27:05 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/23 17:54:43 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	droping_forks(t_philo *philo)
{
	if (pthread_mutex_lock(&(data())->forks[philo->index - 1].mutex))
		return (0);
	(data())->forks[philo->index - 1].turn *= -1;
	if (pthread_mutex_unlock(&(data())->forks[philo->index - 1].mutex))
		return (0);
	if (pthread_mutex_lock
		(&(data())->forks[philo->index - philo->offset].mutex))
		return (0);
	(data())->forks[philo->index - philo->offset].turn *= -1;
	if (pthread_mutex_unlock
		(&(data())->forks[philo->index - philo->offset].mutex))
		return (0);
	return (1);
}

int	taking_forks(t_philo *philo, int count)
{
	if (pthread_mutex_lock(&(data())->forks[philo->index - 1].mutex))
		return (0);
	if ((data())->forks[philo->index - 1].turn == 1)
		count++;
	else
	{
		if (pthread_mutex_unlock(&(data())->forks[philo->index - 1].mutex))
			return (0);
		return (-1);
	}
	if (pthread_mutex_unlock(&(data())->forks[philo->index - 1].mutex))
		return (0);
	if (pthread_mutex_lock
		(&(data())->forks[philo->index - philo->offset].mutex))
		return (0);
	if ((data())->forks[philo->index - philo->offset].turn == -1)
		count++;
	if (pthread_mutex_unlock
		(&(data())->forks[philo->index - philo->offset].mutex))
		return (0);
	if (count == 2)
		return (1);
	return (-1);
}

int	update_state(t_philo *philo)
{
	if (philo->state == 1)
	{
		if (!state1(philo))
			return (0);
	}
	else if (philo->state == 2)
	{
		if (!state2(philo))
			return (0);
	}
	else if (philo->state == 3)
	{
		if (!state3(philo))
			return (0);
	}
	else if (philo->state == 4)
		if (!state4(philo))
			return (0);
	if (pthread_mutex_lock(&(data())->actions_mutex))
		return (0);
	(data())->actions++;
	if (pthread_mutex_unlock(&(data())->actions_mutex))
		return (0);
	return (1);
}

void	*philo(void *src)
{
	t_philo	*philo;

	philo = (t_philo *)src;
	while (1)
	{
		philo->stop = must_i_stop();
		if (!philo->stop)
			return (exit_thread());
		if (philo->stop >= 1)
			return (NULL);
		if (pthread_mutex_lock(&philo->ms_mutex))
			return (NULL);
		if (philo->new_ms)
		{
			philo->new_ms = 0;
			if (pthread_mutex_unlock(&philo->ms_mutex))
				return (NULL);
			philo->ms++;
			if (!update_state(philo))
				return (exit_thread());
		}
		else if (pthread_mutex_unlock(&philo->ms_mutex))
			return (NULL);
	}
	return (NULL);
}
