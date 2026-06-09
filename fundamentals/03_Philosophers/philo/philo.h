/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurochk <akurochk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:59:55 by akurochk          #+#    #+#             */
/*   Updated: 2024/03/26 18:07:21 by akurochk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*m_r;
	pthread_mutex_t	*m_l;
	int				meals;
	int				start_meal;
	struct s_data	*data;	
}	t_philo;

typedef struct s_data
{
	int				nb_ph;
	int				start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				silence;
	pthread_mutex_t	m_status;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_silence;	
	t_philo			*ph;
}	t_data;

/* arg_check.c */
int				is_arg_ok(int ac, char **av);

/* init_data.c */
void			init_data(t_data *data, int ac, char **av);
pthread_mutex_t	*init_forks(int ph_num);
t_philo			*init_philos(t_data *data, pthread_mutex_t *m_f);

/* monitor.c */
void			*monitor(void *pointer);

/* routine.c */
void			*routine(void *ph);

/* threads.c */
int				activate_threads(t_philo *ph, pthread_mutex_t *m_f, int nb_ph);

/* time.c */
void			timer(int ms);
int				get_timestamp(void);

/* utils.c */
void			status(t_philo *ph, char *status, int mode);
int				is_silence(t_data *data);
int				free_all(char *msg, t_data *data, pthread_mutex_t *m_f);

#endif
