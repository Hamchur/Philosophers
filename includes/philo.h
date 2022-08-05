/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:43:02 by hamchur           #+#    #+#             */
/*   Updated: 2022/03/10 13:43:05 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define FORK "\033[1;34mhas taken a fork\033[1;37m"
# define EAT "\033[1;32mis eating\033[1;37m"
# define THINK "\033[1;33mis thinking\033[1;37m"
# define SLEEP "\033[1;36mis sleeping\033[1;37m"
# define DEAD "\033[1;31mdied\033[1;37m"

typedef struct s_data	t_data;

typedef struct s_philo
{
	t_data			*data;
	int				id;
	int				numb_meal;
	long int		last_meal;
	pthread_t		t_id;
	pthread_t		t_alive;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				eat;
	int				die;
	int				sleep;
	int				start;
	int				stop;
	int				opt_eat;
	int				numb_philo;
	pthread_mutex_t	log;
	pthread_mutex_t	finish;
}	t_data;

int			checking_args(char **argv);
int			reading_args(int argc, char **argv, t_data *data);

int			initing_thread_mutex(t_data *data);
int			initing_global_mutex(t_data *data);

int			errors(t_data *data);
void		clean_global_mutex(t_data *data);
void		clean_thread_mutex(t_data *data);
long int	get_time(void);
void		write_log(long int timestamp, int id, const char *status, \
		t_data *data);

void		initing_thread(t_data *data);
void		*handle_thread(void *arg);

void		routine(t_philo *philo);
void		take_fork(t_philo *philo);
void		eat(t_philo *philo);
void		dream(t_philo *philo);
void		*still_alive(void *arg);

#endif
