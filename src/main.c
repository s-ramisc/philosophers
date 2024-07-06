/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:34:25 by sramis-c          #+#    #+#             */
/*   Updated: 2021/11/27 12:34:27 by sramis-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_rules	rule;

	if (get_args(&rule, argc, argv) < 0)
		exit(0);
	create_thread(rule);
	return (0);
}
