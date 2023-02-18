/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 22:26:08 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/24 21:25:05 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	must_i_stop(void)
{
	int	ret;

	ret = -1;
	if (pthread_mutex_lock(&(data())->death_mutex))
		return (0);
	if ((data())->someone_died)
		ret = 1;
	if (pthread_mutex_unlock(&(data())->death_mutex))
		return (0);
	if (pthread_mutex_lock(&(data())->end_mutex))
		return (0);
	if ((data())->someone_finished == (data())->nbr_of_philo)
		ret = 1;
	if (pthread_mutex_unlock(&(data())->end_mutex))
		return (0);
	return (ret);
}

int	equalized(void)
{
	if (pthread_mutex_lock(&(data())->actions_mutex))
		return (0);
	if ((data())->actions == (data())->nbr_of_philo)
	{
		if (pthread_mutex_unlock(&(data())->actions_mutex))
			return (0);
		return (1);
	}
	if (pthread_mutex_unlock(&(data())->actions_mutex))
		return (0);
	return (-1);
}

int	first_statement(t_time *time)
{
	int		i;

	if (gettimeofday(&time->timer, NULL))
		return (0);
	time->old_time = time->timer.tv_sec * 1e+6 + time->timer.tv_usec;
	time->diff = 0;
	i = -1;
	while (++i < (data())->nbr_of_philo)
		if (!print_pls(0, i + 1, "is thinking"))
			return (0);
	if (!(data())->philo[0].meals_to_eat)
		return (0);
	return (1);
}

int	one_more_ms(t_time *time, int i)
{
	if (gettimeofday(&time->timer, NULL))
		return (0);
	time->actual_time = time->timer.tv_sec * 1e+6 + time->timer.tv_usec;
	time->diff += time->actual_time - time->old_time;
	time->old_time = time->actual_time;
	if (time->diff >= 1000)
	{
		if (pthread_mutex_lock(&(data())->actions_mutex))
			return (0);
		(data())->actions = 0;
		if (pthread_mutex_unlock(&(data())->actions_mutex))
			return (0);
		time->diff -= 1000;
		i = -1;
		while (++i < (data())->nbr_of_philo)
		{
			if (pthread_mutex_lock(&(data())->philo[i].ms_mutex))
				return (0);
			(data())->philo[i].new_ms = 1;
			if (pthread_mutex_unlock(&(data())->philo[i].ms_mutex))
				return (0);
		}
	}
	return (1);
}

void	*timer(void *src)
{
	t_time	*time;

	time = (t_time *)src;
	if (!first_statement(time))
		return (exit_thread());
	while (1)
	{
		time->stop = must_i_stop();
		if (!time->stop)
			return (exit_thread());
		if (time->stop == 1)
			return (NULL);
		time->equalizer = equalized();
		if (!time->equalizer)
			return (exit_thread());
		if (time->equalizer == -1)
			continue ;
		if (!one_more_ms(time, 0))
			return (exit_thread());
	}
	return (NULL);
}
