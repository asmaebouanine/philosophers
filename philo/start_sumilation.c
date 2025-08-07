/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sumilation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:17:10 by asbouani          #+#    #+#             */
/*   Updated: 2025/07/20 15:55:41 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_one_philo(t_table *sim)
{
	log_status(&sim->philo[0], "has taken a fork");
	ft_usleep(sim->time_to_die, sim);
	log_status(&sim->philo[0], "died");
	return (1);
}

int	start_simulation(t_table *sim)
{
	int	i;

	i = 0;
	sim->start_simulation = get_time();
	sim->end_simulation = 0;
	pthread_mutex_init(&sim->data_lock, NULL);
	pthread_mutex_init(&sim->print_lock, NULL);
	pthread_mutex_init(&sim->state_lock, NULL);
	if (sim->nb_of_philo == 1)
		return (handle_one_philo(sim));
	while (i < sim->nb_of_philo)
	{
		sim->philo[i].last_time_eating = sim->start_simulation;
		if (pthread_create(&sim->philo[i].thread, NULL,
				philosopher_routine, &sim->philo[i]))
			return (1);
		usleep(100);
		i++;
	}
	return (0);
}
