/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 21:53:54 by asbouani          #+#    #+#             */
/*   Updated: 2025/07/20 16:08:52 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *sim)
{
	sim->fork = malloc(sizeof(t_fork) * sim->nb_of_philo);
	if (!sim->fork)
		return (1);
	sim->philo = malloc(sizeof(t_philo) * sim->nb_of_philo);
	if (!sim->philo)
	{
		free(sim->fork);
		return (1);
	}
	return (0);
}

int	init_fork(t_table *sim)
{
	int	i;

	i = 0;
	while (i < sim->nb_of_philo)
	{
		if (pthread_mutex_init(&sim->fork[i].fork, NULL))
		{
			while (i-- >= 0)
				pthread_mutex_destroy(&sim->fork[i].fork);
			free(sim->philo);
			free(sim->fork);
			return (1);
		}
		i++;
	}
	return (0);
}

long	get_time(void)
{
	struct timeval	tv;
	long			seconds_in_ms;
	long			microseconds_in_ms;
	long			t_milliseconds;

	gettimeofday(&tv, NULL);
	seconds_in_ms = tv.tv_sec * 1000;
	microseconds_in_ms = tv.tv_usec / 1000;
	t_milliseconds = seconds_in_ms + microseconds_in_ms;
	return (t_milliseconds);
}

int	init_philosophers(t_table *sim)
{
	long	start_simulation;
	int		i;

	start_simulation = get_time();
	i = 0;
	while (i < sim->nb_of_philo)
	{
		sim->philo[i].id = i + 1;
		sim->philo[i].table = sim;
		sim->philo[i].nbr_meal_to_eat = sim->number_of_time_to_eat;
		sim->philo[i].last_time_eating = start_simulation;
		sim->philo[i].thread = 0;
		if (sim->philo[i].id % 2 == 0)
		{
			sim->philo[i].right_fork = &sim->fork[i];
			sim->philo[i].left_fork = &sim->fork[(i + 1) % sim->nb_of_philo];
		}
		else
		{
			sim->philo[i].left_fork = &sim->fork[i];
			sim->philo[i].right_fork = &sim->fork[(i + 1) % sim->nb_of_philo];
		}
		i++;
	}
	return (0);
}
