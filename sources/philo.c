/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:18:42 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/10 14:18:44 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!checking_args(argv))
		{
			if (reading_args(argc, argv, &data))
				return (1);
			if (initing_global_mutex(&data) || initing_thread_mutex(&data))
				return (1);
			data.start = get_time();
			initing_thread(&data);
			clean_global_mutex(&data);
			clean_thread_mutex(&data);
			free(data.philo);
			return (0);
		}
		return (1);
	}
	return (0);
}
