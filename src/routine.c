/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:28:07 by sramis-c          #+#    #+#             */
/*   Updated: 2022/02/04 19:28:09 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*routine(void *arg)
{
	t_philo	*cphilo;

	cphilo = (t_philo *)arg;
	usleep(1000);
	get_time(1);
	cphilo->time_since_last_meal = get_time(0);
	while (1)
	{
		take_fork(cphilo);
		eat(cphilo);
		pthread_mutex_unlock(&cphilo->right_fork);
		pthread_mutex_unlock(&cphilo->next->right_fork);
		to_sleep(cphilo);
		think(cphilo);
		if (cphilo->number_of_meals == cphilo->nb_eat)
			cphilo->is_full = 1;
	}
	return (0);
}
