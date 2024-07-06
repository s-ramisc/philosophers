/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:01:17 by sramis-c          #+#    #+#             */
/*   Updated: 2021/11/29 13:20:05 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_rules
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_eat;
}				t_rules;

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_since_last_meal;
	int				nb_eat;	
	int				number_of_meals;
	int				is_full;
	pthread_t		philo;
	struct s_philo	*next;
	struct s_philo	*prev;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
}					t_philo;

int			get_args(t_rules *rule, int argc, char **argv);
void		create_thread(t_rules rule);
void		*routine(void *arg);
int			get_time(int a);
void		take_fork(t_philo *cphilo);
void		eat(t_philo *cphilo);
void		to_sleep(t_philo *cphilo);
void		think(t_philo *cphilo);

#endif
