/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:28:07 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/30 18:28:10 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_fork(t_philo *philo)
{
	t_data	*data;
	int		id;

	id = philo->id;
	data = philo->data;
	pthread_mutex_lock(&philo->fork);
	if (id == data->numb_philo - 1)
		pthread_mutex_lock(&data->philo[0].fork);
	else
		pthread_mutex_lock(&data->philo[id + 1].fork);
	pthread_mutex_lock(&data->log);
	write_log(get_time(), philo->id, FORK, data);
	write_log(get_time(), philo->id, FORK, data);
	pthread_mutex_unlock(&data->log);
}

void	eat(t_philo *philo)
{
	t_data	*data;
	int		id;

	data = philo->data;
	id = philo->id;
	philo->last_meal = get_time();
	philo->numb_meal += 1;
	pthread_mutex_lock(&philo->data->log);
	write_log(get_time(), philo->id, EAT, data);
	pthread_mutex_unlock(&philo->data->log);
	if (data->eat > data->die)
		usleep((data->die * 2) * 1000);
	else
		usleep(data->eat * 950);
	pthread_mutex_unlock(&philo->fork);
	if (id == data->numb_philo - 1)
		pthread_mutex_unlock(&data->philo[0].fork);
	else
		pthread_mutex_unlock(&data->philo[id + 1].fork);
}

void	dream(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->log);
	write_log(get_time(), philo->id, SLEEP, philo->data);
	pthread_mutex_unlock(&philo->data->log);
	if (philo->data->sleep > philo->data->die)
		usleep((philo->data->die * 2) * 1000);
	else
		usleep(philo->data->sleep * 1000);
	pthread_mutex_lock(&philo->data->log);
	write_log(get_time(), philo->id, THINK, philo->data);
	pthread_mutex_unlock(&philo->data->log);
}

void	routine(t_philo *philo)
{
	take_fork(philo);
	eat(philo);
	dream(philo);
}
