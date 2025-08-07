/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asbouani <asbouani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:29:38 by asbouani          #+#    #+#             */
/*   Updated: 2025/07/17 21:49:48 by asbouani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(char *str, int *count)
{
	long	result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = 0;
	while (str[i] == '+')
		i++;
	j = i;
	while (str[i])
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	*count = i - j;
	return (result);
}

int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '+')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

char	*skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	return (str + i);
}
