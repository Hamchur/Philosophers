/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:30:11 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/28 19:30:13 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	errors(t_data *data)
{
	free(data->philo);
	printf("Errors");
	return (1);
}

void	clean_global_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->log);
	pthread_mutex_destroy(&data->finish);
}

void	clean_thread_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->numb_philo)
		pthread_mutex_destroy(&data->philo[i].fork);
}

long int	get_time(void)
{
	struct timeval	tv;
	long int		time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	write_log(long int timestamp, int id, const char *status, t_data *data)
{
	int	time;

	pthread_mutex_lock(&data->finish);
	if (data->stop == 1)
	{
		pthread_mutex_unlock(&data->finish);
		return ;
	}
	pthread_mutex_unlock(&data->finish);
	time = timestamp - data->start;
	printf("%d philosopher №%d %s\n", time, id + 1, status);
}
