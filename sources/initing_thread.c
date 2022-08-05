/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initing_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:51:11 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/28 19:51:13 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	only_one(t_philo *philo)
{
	if (philo->data->numb_philo == 1)
	{
		pthread_mutex_lock(&philo->data->log);
		write_log(get_time(), philo->id, FORK, philo->data);
		usleep(philo->data->die * 1000);
		write_log(get_time(), philo->id, DEAD, philo->data);
		pthread_mutex_unlock(&philo->data->log);
		return (1);
	}
	return (0);
}

void	*handle_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (only_one(philo))
		return (NULL);
	if (philo->id % 2 == 1)
		usleep(philo->data->eat * 1000);
	philo->numb_meal = 0;
	while (!philo->data->stop && philo->numb_meal != philo->data->opt_eat)
	{
		pthread_create(&philo->t_alive, NULL, &still_alive, philo);
		pthread_detach(philo->t_alive);
		routine(philo);
	}
	usleep(philo->data->die * 1000);
	return (NULL);
}

void	initing_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->numb_philo)
		pthread_create(&data->philo[i].t_id, NULL, \
				&handle_thread, &data->philo[i]);
	i = -1;
	while (++i < data->numb_philo)
		pthread_join(data->philo[i].t_id, NULL);
}
