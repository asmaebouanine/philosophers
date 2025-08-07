/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sumilation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:27:03 by asbouani          #+#    #+#             */
/*   Updated: 2025/07/20 15:47:17 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_status(t_table *sim, int i)
{
	long	duration;

	pthread_mutex_lock(&sim->data_lock);
	duration = get_time() - sim->philo[i].last_time_eating;
	if (duration > sim->time_to_die)
	{
		pthread_mutex_lock(&sim->state_lock);
		sim->end_simulation = 1;
		pthread_mutex_unlock(&sim->state_lock);
		printf("%ld %d died\n", get_time() - sim->start_simulation,
			sim->philo[i].id);
		pthread_mutex_unlock(&sim->data_lock);
		return (1);
	}
	pthread_mutex_unlock(&sim->data_lock);
	return (0);
}

void	check_simulation(t_table *sim)
{
	int	i;
	int	full_philos;

	while (1)
	{
		(1) && (i = 0, full_philos = 1);
		while (i < sim->nb_of_philo)
		{
			if (philosopher_status(sim, i) == 1)
				return ;
			pthread_mutex_lock(&sim->data_lock);
			if (sim->exist_option && sim->philo[i].nbr_meal_to_eat > 0)
				full_philos = 0;
			pthread_mutex_unlock(&sim->data_lock);
			i++;
		}
		if (sim->exist_option && full_philos)
		{
			pthread_mutex_lock(&sim->state_lock);
			sim->end_simulation = 1;
			pthread_mutex_unlock(&sim->state_lock);
			return ;
		}
		usleep(1000);
	}
}
