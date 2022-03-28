/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:02:28 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/28 19:08:11 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	ph_init(int argc, char **argv, t_philo *ph)
{
	int	i;

	i = 0;
	ph->prog_state = 1;
	ph->philo_num = ft_atoi(argv[1]);
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ph->eat_num = ft_atoi(argv[5]);
	ph->philos = malloc(sizeof(pthread_t) * ph->philo_num);
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->philo_num);
	ph->attrs = malloc(sizeof(t_philo_attr) * ph->philo_num);
	while (i < ph->philo_num)
	{
		pthread_mutex_init(&(ph->forks[i++]), NULL);
	}
	return (0);
}

int	ph_destroy(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->philo_num)
	{
		pthread_mutex_destroy(&(ph->forks[i]));
		i++;
	}
	free(ph->forks);
	free(ph->philos);
	return (0);
}

void	sleep(int time)
{
	usleep(time);
}

void	think(int time)
{
	usleep(time);
}

void	eat(t_philo_attr *attr)
{
	
}

void	*philo_routine(void *arg)
{
	t_philo_attr	*attr;

	attr = (t_philo_attr *) arg;


}

int	main(int argc, char **argv)
{
	int		i;
	t_philo	ph;

	i = 0;
	if (argc < 5)
		return (write(1, "Args error\n", 11));
	if (!(ft_isnum(argv[1]) && ft_isnum(argv[2])
			&& ft_isnum(argv[3]) && ft_isnum(argv[4])))
		return (write(1, "Args error\n", 11));
	if (argc == 6 && !ft_isnum(argv[5]))
		return (write(1, "Args error\n", 11));
	ph_init(argc, argv, &ph);
	while (i < ph.philo_num)
	{
		pthread_create(&(ph.philos[i]), NULL, hw, ft_itoa(i));
		pthread_detach(ph.philos[i]);
		//pthread_join(ph.philos[i], NULL);
		i++;
	}
	ph_destroy(&ph);
}
