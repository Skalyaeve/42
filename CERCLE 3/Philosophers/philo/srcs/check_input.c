/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:08:21 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/24 21:22:19 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	check_digits(int ac, char **av, int i)
{
	while (av[1][++i])
		if (!is_digit(av[1][i]))
			return (0);
	i = -1;
	while (av[2][++i])
		if (!is_digit(av[2][i]))
			return (0);
	i = -1;
	while (av[3][++i])
		if (!is_digit(av[3][i]))
			return (0);
	i = -1;
	while (av[4][++i])
		if (!is_digit(av[4][i]))
			return (0);
	i = -1;
	while (ac == 6 && av[5][++i])
		if (!is_digit(av[5][i]))
			return (0);
	return (1);
}

void	fill_forks_data(int i)
{
	pthread_mutex_init(&(data())->forks[i].mutex, NULL);
	(data())->forks[i].turn = 1;
	if (!((i + 1) % 2))
		(data())->forks[i].turn = -1;
}

int	fill_philo_data(int ac, char **av, int i)
{
	while (++i < (data())->nbr_of_philo)
	{
		fill_forks_data(i);
		pthread_mutex_init(&(data())->philo[i].ms_mutex, NULL);
		(data())->philo[i].index = i + 1;
		(data())->philo[i].ms = 0;
		(data())->philo[i].new_ms = 0;
		(data())->philo[i].state = 1;
		(data())->philo[i].dying = 0;
		(data())->philo[i].eating = 0;
		(data())->philo[i].sleeping = 0;
		(data())->philo[i].meals_ate = 0;
		(data())->philo[i].nbr_of_philo = (data())->nbr_of_philo;
		(data())->philo[i].offset = 0;
		if ((data())->philo[i].index == (data())->philo[i].nbr_of_philo)
			(data())->philo[i].offset = (data())->philo[i].index;
		(data())->philo[i].tt_die = ft_long_long_atoi(av[2]);
		(data())->philo[i].tt_eat = ft_long_long_atoi(av[3]);
		(data())->philo[i].tt_sleep = ft_long_long_atoi(av[4]);
		(data())->philo[i].meals_to_eat = -1;
		if (ac == 6)
			(data())->philo[i].meals_to_eat = ft_long_long_atoi(av[5]);
	}
	return (1);
}

int	check_input(int ac, char **av)
{
	if (!check_digits(ac, av, -1))
		return (0);
	(data())->nbr_of_philo = ft_long_long_atoi(av[1]);
	(data())->philo = malloc(sizeof(t_philo) * (data())->nbr_of_philo);
	if (!(data())->philo)
		return (0);
	(data())->forks = malloc(sizeof(t_philo) * (data())->nbr_of_philo);
	if (!(data())->forks)
		return (0);
	(data())->someone_died = 0;
	(data())->someone_finished = 0;
	(data())->actions = (data())->nbr_of_philo;
	pthread_mutex_init(&(data())->actions_mutex, NULL);
	pthread_mutex_init(&(data())->death_mutex, NULL);
	pthread_mutex_init(&(data())->end_mutex, NULL);
	pthread_mutex_init(&(data())->speak_mutex, NULL);
	return (fill_philo_data(ac, av, -1));
}
