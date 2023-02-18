/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:30:07 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/20 23:54:12 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	exit_pls(void)
{
	if ((data())->philo)
		free((data())->philo);
	if ((data())->forks)
		free((data())->forks);
	return (0);
}

void	*exit_thread(void)
{
	if (pthread_mutex_lock(&(data())->death_mutex))
		return (0);
	(data())->someone_died = 1;
	if (pthread_mutex_unlock(&(data())->death_mutex))
		return (0);
	return (NULL);
}

int	print_pls(int ms, int index, char *str)
{
	if (pthread_mutex_lock(&(data())->death_mutex))
		return (0);
	if ((data())->someone_died)
	{
		if (pthread_mutex_unlock(&(data())->death_mutex))
			return (0);
		return (1);
	}
	if (ft_strchr(str, "died") != -1)
		(data())->someone_died = 1;
	if (pthread_mutex_unlock(&(data())->death_mutex))
		return (0);
	if (pthread_mutex_lock(&(data())->speak_mutex))
		return (0);
	printf("%i ms %i %s\n", ms, index, str);
	if (ft_strchr(str, "has taken a fork") != -1)
		printf("%i ms %i %s\n", ms, index, str);
	if (pthread_mutex_unlock(&(data())->speak_mutex))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac > 4 && ac < 7)
	{
		data();
		if (!check_input(ac, av))
			return (exit_pls());
		i = -1;
		while (++i < (data())->nbr_of_philo)
			pthread_create(&(data())->philo[i].thread,
				NULL, philo, &(data())->philo[i]);
		pthread_create(&(data())->time.thread, NULL, timer, &(data())->time);
		i = -1;
		while (++i < (data())->nbr_of_philo)
			pthread_join((data())->philo[i].thread, NULL);
		pthread_join((data())->time.thread, NULL);
		return (exit_pls());
	}
	return (0);
}
