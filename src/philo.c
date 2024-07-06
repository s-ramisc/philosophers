/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:19:16 by sramis-c          #+#    #+#             */
/*   Updated: 2021/11/29 14:19:17 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

t_philo	*create_philo(void *content, t_philo *next, t_philo *prev)
{
	t_rules	*rule;
	t_philo	*new;

	rule = content;
	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->time_to_die = rule->time_to_die;
	new->time_to_eat = rule->time_to_eat;
	new->time_to_sleep = rule->time_to_sleep;
	new->nb_eat
		= rule->nb_eat;
	new->number_of_meals = 0;
	new->is_full = 0;
	new->prev = prev;
	new->next = next;
	if (prev != NULL)
		prev->next = new;
	pthread_mutex_init(&new->right_fork, NULL);
	if (next != NULL)
		next->prev = new;
	return (new);
}

void	check_death(t_rules rule, t_philo **philosopher)
{
	int	full_philos;
	int	i;

	full_philos = 0;
	while (full_philos != rule.number_of_philosophers)
	{
		i = 0;
		while (i < rule.number_of_philosophers)
		{
			if (philosopher[i]->is_full == 1)
			{
				full_philos++;
				philosopher[i]->is_full = 2;
			}
			if ((get_time(0) - philosopher[i]->time_since_last_meal)
				> philosopher[i]->time_to_die)
			{
				printf("[%d]\t\tPhilo %d died\n",
					get_time(0), philosopher[i]->id);
				return ;
			}
			i++;
		}
	}
}

void	free_all(t_rules rule, t_philo **philosopher)
{
	int	i;

	i = 0;
	while (i < rule.number_of_philosophers)
	{
		pthread_detach(philosopher[i]->philo);
		pthread_mutex_destroy(&philosopher[i]->right_fork);
		free(philosopher[i]);
		i++;
	}
	free(philosopher);
}

void	create_thread(t_rules rule)
{
	t_philo	**philosopher;
	int		i;

	philosopher = malloc(rule.number_of_philosophers * sizeof(t_philo *));
	i = 0;
	philosopher[i] = create_philo(&rule, NULL, NULL);
	philosopher[i]->id = i + 1;
	pthread_create(&philosopher[i]->philo, NULL, &routine, philosopher[i]);
	while (++i < rule.number_of_philosophers - 1)
	{
		philosopher[i] = create_philo(&rule, NULL, philosopher[i - 1]);
		philosopher[i]->id = i + 1;
		pthread_create(&philosopher[i]->philo, NULL, &routine, philosopher[i]);
	}
	if (i >= 1 && rule.number_of_philosophers != 1)
	{
		philosopher[i] = create_philo(&rule,
				philosopher[0], philosopher[i - 1]);
		philosopher[i]->id = i + 1;
		pthread_create(&philosopher[i]->philo, NULL, &routine, philosopher[i]);
	}
	usleep(2000);
	check_death(rule, philosopher);
	free_all(rule, philosopher);
}
