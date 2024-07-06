/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:37:27 by sramis-c          #+#    #+#             */
/*   Updated: 2022/02/04 19:37:29 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	get_time(int a)
{
	static struct timeval	start_time;
	struct timeval			current_time;
	int						d_time;

	if (a != 0)
		gettimeofday(&start_time, NULL);
	gettimeofday(&current_time, NULL);
	d_time = (current_time.tv_sec - start_time.tv_sec) * 1000
		+ (current_time.tv_usec - start_time.tv_usec) / 1000;
	return (d_time);
}

void	think(t_philo *cphilo)
{
	printf("[%d]\t\tPhilo %d is thinking\n", get_time(0), cphilo->id);
}

void	to_sleep(t_philo *cphilo)
{
	int	bedtime;

	bedtime = get_time(0);
	printf("[%d]\t\tPhilo %d is sleeping\n", bedtime, cphilo->id);
	while (get_time(0) < bedtime + cphilo->time_to_sleep)
	{
		usleep(100);
	}
}

void	eat(t_philo *cphilo)
{
	int	lunchtime;

	lunchtime = get_time(0);
	cphilo->time_since_last_meal = lunchtime;
	printf("[%d]\t\tPhilo %d is eating\n", lunchtime, cphilo->id);
	while (get_time(0) < lunchtime + cphilo->time_to_eat)
	{
		usleep(100);
	}
	cphilo->number_of_meals++;
}

void	take_fork(t_philo *cphilo)
{
	if (cphilo->next == NULL)
	{
		printf("[%d]\t\tPhilo %d has taken a fork\n", get_time(0), cphilo->id);
		while (1)
			usleep(100);
	}
	else if (cphilo->id % 2 != 0)
	{
		pthread_mutex_lock(&cphilo->right_fork);
		printf("[%d]\t\tPhilo %d has taken a fork\n", get_time(0), cphilo->id);
		pthread_mutex_lock(&cphilo->next->right_fork);
		printf("[%d]\t\tPhilo %d has taken a fork\n", get_time(0), cphilo->id);
	}
	else
	{
		usleep(100);
		pthread_mutex_lock(&cphilo->next->right_fork);
		printf("[%d]\t\tPhilo %d has taken a fork\n", get_time(0), cphilo->id);
		pthread_mutex_lock(&cphilo->right_fork);
		printf("[%d]\t\tPhilo %d has taken a fork\n", get_time(0), cphilo->id);
	}
}
