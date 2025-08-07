/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:34:03 by asbouani          #+#    #+#             */
/*   Updated: 2025/07/20 16:23:42 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_clean(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_of_philo)
	{
		if (table->philo[i].thread > 0)
			pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	i = -1;
	while (++i < table->nb_of_philo)
		pthread_mutex_destroy(&table->fork[i].fork);
	pthread_mutex_destroy(&table->data_lock);
	pthread_mutex_destroy(&table->print_lock);
	pthread_mutex_destroy(&table->state_lock);
	free(table->fork);
	free(table->philo);
}

int	fill_table_args(t_table *table, int arg, long nbr)
{
	if (arg == 1)
		table->nb_of_philo = nbr;
	else if (arg == 2)
		table->time_to_die = nbr;
	else if (arg == 3)
		table->time_to_eat = nbr;
	else if (arg == 4)
		table->time_to_sleep = nbr;
	else if (arg == 5)
	{
		table->number_of_time_to_eat = nbr;
		table->exist_option = 1;
	}
	else
		return (1);
	return (0);
}

int	parse_args(int ac, char **av, t_table *table)
{
	char	*str;
	long	nbr;
	int		count;
	int		i;

	(1) && (i = 1, count = 0);
	memset(table, 0, sizeof(t_table));
	if (ac != 5 && ac != 6)
		return (printf("Error: wrong number of arguments\n"), 1);
	while (av[i])
	{
		str = skip_space(av[i]);
		if (*str == '\0' || check_digit(str))
			return (printf("Error: invalid input\n"), 1);
		nbr = ft_atoi(str, &count);
		if (nbr == 0 || nbr > INT_MAX || count > 10)
			return (printf("Error: invalid input\n"), 1);
		if (fill_table_args(table, i, nbr))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;

	if (parse_args(ac, av, &table))
		return (1);
	if (init_table(&table) || init_fork(&table))
		return (1);
	init_philosophers(&table);
	if (start_simulation(&table))
		return (ft_clean(&table), 1);
	check_simulation(&table);
	ft_clean(&table);
	return (0);
}
