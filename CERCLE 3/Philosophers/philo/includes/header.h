/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 20:32:18 by anguinau          #+#    #+#             */
/*   Updated: 2022/06/23 17:56:32 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_forks
{
	pthread_mutex_t	mutex;
	int				turn;
}					t_forks;

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	ms_mutex;
	int				index;
	int				ms;
	int				new_ms;
	int				state;
	int				dying;
	int				eating;
	int				sleeping;
	int				meals_ate;
	int				nbr_of_philo;
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				meals_to_eat;
	int				stop;
	int				offset;
}					t_philo;

typedef struct s_time
{
	pthread_t		thread;
	struct timeval	timer;
	long long		old_time;
	long long		actual_time;
	long long		diff;
	int				equalizer;
	int				stop;
}					t_time;

typedef struct s_data
{
	t_time			time;
	t_philo			*philo;
	t_forks			*forks;
	pthread_mutex_t	actions_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	speak_mutex;
	int				actions;
	int				someone_died;
	int				someone_finished;
	int				nbr_of_philo;
}					t_data;

t_data		*data(void);
int			check_input(int ac, char **av);
void		*philo(void *src);
void		*timer(void *src);
int			print_pls(int ms, int index, char *str);
int			ft_strchr(char *str, const char *to_find);
void		*exit_thread(void);
int			must_i_stop(void);
int			state1(t_philo *philo);
int			state2(t_philo *philo);
int			state3(t_philo *philo);
int			state4(t_philo *philo);
int			taking_forks(t_philo *philo, int count);
int			droping_forks(t_philo *philo);
long long	ft_long_long_atoi(const char *nptr);
int			is_digit(char c);

#	endif