/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:08:21 by sramis-c          #+#    #+#             */
/*   Updated: 2021/11/29 13:08:23 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(const char *str)
{
	long int	i;
	long int	k;
	long int	r;

	i = 0;
	k = 1;
	r = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			k = -k;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = ((r * 10) + (str[i] - '0') * k);
		i++;
	}
	return ((int)r);
}

void	check_value(char *value)
{
	int	i;

	i = 0;
	while (value[i] != '\0')
	{
		if (!(value[i] >= '0' && value[i] <= '9'))
		{
			printf("ERROR: Wrong parameters\n");
			exit(0);
		}
		i++;
	}
}

int	get_args(t_rules *rule, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		check_value(argv[i]);
		i++;
	}
	if (argc == 5 || argc == 6)
	{
		rule->number_of_philosophers = ft_atoi(argv[1]);
		if (rule->number_of_philosophers == 0)
			exit(0);
		rule->time_to_die = ft_atoi(argv[2]);
		rule->time_to_eat = ft_atoi(argv[3]);
		rule->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			rule->nb_eat = ft_atoi(argv[5]);
		else
			rule->nb_eat = INT32_MAX;
	}
	else
		exit (0);
	return (0);
}
