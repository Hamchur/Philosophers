/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:26:03 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/28 19:26:07 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	initing_thread_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->numb_philo)
	{
		if (pthread_mutex_init(&data->philo[i].fork, NULL))
		{
			while (--i)
				pthread_mutex_destroy(&data->philo[i].fork);
			clean_global_mutex(data);
			return (errors(data));
		}
	}
	return (0);
}

int	initing_global_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->log, NULL))
		return (errors(data));
	if (pthread_mutex_init(&data->finish, NULL))
	{
		pthread_mutex_destroy(&data->log);
		return (errors(data));
	}
	return (0);
}
