/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   still_alive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:26:34 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/30 18:26:36 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*still_alive(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	usleep(philo->data->die * 1000);
	if (get_time() - philo->last_meal >= philo->data->die)
	{
		if (philo->data->opt_eat != philo->numb_meal)
		{
			pthread_mutex_lock(&philo->data->log);
			write_log(get_time(), philo->id, DEAD, philo->data);
			pthread_mutex_unlock(&philo->data->log);
		}
		pthread_mutex_lock(&philo->data->finish);
		philo->data->stop = 1;
		pthread_mutex_unlock(&philo->data->finish);
	}
	return (NULL);
}
