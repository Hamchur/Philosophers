/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:20:31 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/28 18:20:34 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while (str[++i])
		j = 10 * j + (str[i] - '0');
	return (j);
}

int	checking_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
		}
		if (j >= 11)
			return (1);
	}
	return (0);
}

int	reading_args(int argc, char **argv, t_data *data)
{
	int	i;

	data->numb_philo = ft_atoi(argv[1]);
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	data->stop = 0;
	if (argc == 6)
		data->opt_eat = ft_atoi(argv[5]);
	else
		data->opt_eat = -1;
	if (data->numb_philo == 0 || data->die == 0)
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->numb_philo);
	if (!data->philo)
		return (1);
	i = -1;
	while (++i < data->numb_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i;
	}
	return (0);
}
