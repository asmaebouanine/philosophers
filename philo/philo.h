/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 09:56:59 by asbouani          #+#    #+#             */
/*   Updated: 2025/07/20 16:11:37 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mtx;

typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	t_fork		*right_fork;
	t_fork		*left_fork;
	long		last_time_eating;
	int			nbr_meal_to_eat;
	pthread_t	thread;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	int		nb_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_of_time_to_eat;
	int		exist_option;
	int		end_simulation;
	long	start_simulation;
	t_mtx	data_lock;
	t_mtx	print_lock;
	t_mtx	state_lock;
	t_fork	*fork;
	t_philo	*philo;
}	t_table;

int		init_philosophers(t_table *sim);
int		check_digit(char *str);
int		init_table(t_table *sim);
int		philosopher_status(t_table *sim, int i);
int		init_fork(t_table *sim);
void	check_simulation(t_table *sim);
int		start_simulation(t_table *sim);
long	ft_atoi(char *str, int *count);
long	get_time(void);
void	*philosopher_routine(void *arg);
void	log_status(t_philo *philo, char *message);
char	*skip_space(char *str);
void	ft_usleep(long duration_ms, t_table *table);

#endif