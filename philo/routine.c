/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:07:38 by asbouani          #+#    #+#             */
/*   Updated: 2025/08/07 13:20:45 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_status(t_philo *philo, char *message)
{
	long	time_now;
	int		ended;

	pthread_mutex_lock(&philo->table->print_lock);
	pthread_mutex_lock(&philo->table->state_lock);
	ended = philo->table->end_simulation;
	pthread_mutex_unlock(&philo->table->state_lock);
	if (ended)
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	time_now = get_time() - philo->table->start_simulation;
	printf("%ld %d %s\n", time_now, philo->id, message);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	ft_usleep(long duration_ms, t_table *table)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < duration_ms)
	{
		pthread_mutex_lock(&table->state_lock);
		if (table->end_simulation)
		{
			pthread_mutex_unlock(&table->state_lock);
			break ;
		}
		pthread_mutex_unlock(&table->state_lock);
		usleep(100);
	}
}

void	philosopher_cycle(t_philo *philo)
{
	
	pthread_mutex_lock(&philo->right_fork->fork);
	log_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->left_fork->fork);
	log_status(philo, "has taken a fork");
	log_status(philo, "is eating");
	pthread_mutex_lock(&philo->table->data_lock);
	philo->last_time_eating = get_time();
	if (philo->table->exist_option && philo->nbr_meal_to_eat > 0)
		philo->nbr_meal_to_eat--;
	pthread_mutex_unlock(&philo->table->data_lock);
	ft_usleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(&philo->left_fork->fork);
	pthread_mutex_unlock(&philo->right_fork->fork);
	log_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep, philo->table);
	log_status(philo, "is thinking");
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&philo->table->state_lock);
		if (philo->table->end_simulation)
		{
			pthread_mutex_unlock(&philo->table->state_lock);
			break ;
		}
		pthread_mutex_unlock(&philo->table->state_lock);
		philosopher_cycle(philo);
	}
	return (NULL);
}
