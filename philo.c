/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:02:28 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/29 17:06:53 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	ph_init(int argc, char **argv, t_philo *ph)
{
	int	i;

	i = 0;
	ph->prog_state = 1;
	gettimeofday(&ph->prog_start_time, NULL);
	ph->philo_num = ft_atoi(argv[1]);
	ph->time_to_die = ft_atoi(argv[2]);
	ph->time_to_eat = ft_atoi(argv[3]);
	ph->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ph->eat_num = ft_atoi(argv[5]);
	ph->philos = malloc(sizeof(pthread_t) * ph->philo_num);
	ph->forks = malloc(sizeof(pthread_mutex_t) * ph->philo_num);
	if (ph->philos == NULL || ph->forks == NULL)
		return (ph_destroy(ph));
	while (i < ph->philo_num)
	{
		pthread_mutex_init(&(ph->forks[i]), NULL);
		i++;
	}
	return (0);
}

int	attrs_destroy(t_philo_attr **attrs)
{
	if (attrs == NULL)
		return (0);
	ph_destroy(attrs[0]->ph);
	free(*attrs);
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
	return (1);
}

int	msg(t_philo_attr *attr, int type)
{
	struct timeval	cur_time;
	long int		time;
	int				state;

	state = attr->ph->prog_state;
	gettimeofday(&cur_time, NULL);
	time = (cur_time.tv_sec - attr->ph->prog_start_time.tv_sec) * 1000
		+ (cur_time.tv_usec - attr->ph->prog_start_time.tv_usec) / 1000;
	if (state && type == 0)
		printf("%ld: %d is eating\n", time, attr->id);
	if (state && type == 1)
		printf("%ld: %d is sleeping\n", time, attr->id);
	if (state && type == 2)
		printf("%ld: %d is thinking\n", time, attr->id);
	if (state && type == 3)
		printf("%ld: %d has taken fork\n", time, attr->id);
	if (type == 4)
		printf("%ld: %d died\n", time, attr->id);
	return (0);
}

void	psleep(t_philo_attr *attr)
{
	msg(attr, 1);
	if (attr->ph->prog_state == 0)
		return ;
	attr->starve_time += attr->ph->time_to_sleep;
	if (attr->starve_time < attr->ph->time_to_die)
		usleep(attr->ph->time_to_sleep * 1000);
	else
		attr->ph->prog_state = msg(attr, 4);
}

void	think(t_philo_attr *attr)
{
	int				my_fork;
	int				right_fork;
	struct timeval	start_time;
	struct timeval	end_time;

	msg(attr, 2);
	gettimeofday(&start_time, NULL);
	my_fork = 1;
	right_fork = 1;
	if (attr->ph->prog_state == 0)
		return ;
	while (my_fork != 0 && right_fork != 0)
	{
		my_fork = pthread_mutex_trylock(&(attr->ph->forks[attr->id]));
		if (my_fork != 0)
			continue ;
		right_fork = pthread_mutex_trylock(&(attr->ph->forks[(attr->id + 1)
					% attr->ph->philo_num]));
		if (right_fork != 0)
		{
			pthread_mutex_unlock(&(attr->ph->forks[attr->id]));
			my_fork = 1;
		}
	}
	msg(attr, 3);
	gettimeofday(&end_time, NULL);
	attr->starve_time += (end_time.tv_sec - start_time.tv_sec) * 1000
		+ (end_time.tv_usec - start_time.tv_usec) / 1000;
	if (attr->starve_time > attr->ph->time_to_die)
		attr->ph->prog_state = msg(attr, 4);
}

void	eat(t_philo_attr *attr)
{
	msg(attr, 0);
	attr->starve_time += attr->ph->time_to_eat;
	if (attr->ph->prog_state != 0 && attr->starve_time < attr->ph->time_to_die)
	{
		usleep(attr->ph->time_to_eat * 1000);
		attr->starve_time = 0;
	}
	else
		attr->ph->prog_state = msg(attr, 4);
	pthread_mutex_unlock(&(attr->ph->forks[attr->id]));
	pthread_mutex_unlock(&(attr->ph->forks[(attr->id + 1) % attr->ph->philo_num]));
}

void	*philo_routine(void *arg)
{
	t_philo_attr	*attr;

	attr = (t_philo_attr *) arg;
	while (attr->ph->prog_state != 0)
	{
		think(attr);
		eat(attr);
		psleep(attr);
	}
	return (NULL);
}

int	attrs_init(t_philo_attr **attrs, t_philo *ph)
{
	int	i;

	i = 0;
	*attrs = malloc(sizeof(t_philo_attr) * ph->philo_num);
	if (attrs == NULL)
		return (1);
	while (i < ph->philo_num)
	{
		(*attrs)[i].id = i;
		(*attrs)[i].starve_time = 0;
		(*attrs)[i].ph = ph;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				i;
	t_philo			ph;
	t_philo_attr	*attrs;

	i = 0;
	attrs = NULL;
	if (argc < 5)
		return (write(1, "Args error\n", 11));
	if (!(ft_isnum(argv[1]) && ft_isnum(argv[2])
			&& ft_isnum(argv[3]) && ft_isnum(argv[4])))
		return (write(1, "Args error\n", 11));
	if (argc == 6 && !ft_isnum(argv[5]))
		return (write(1, "Args error\n", 11));
	if (ph_init(argc, argv, &ph))
		return (ph_destroy(&ph));
	if (attrs_init(&attrs, &ph))
		return (attrs_destroy(&attrs));
	for (int i = 0; i < ph.philo_num; i++)
	{
		printf("attr %d: id= %d, st_t= %d, ph= %p \n", i,
			attrs[i].id, attrs[i].starve_time, attrs[i].ph);
	}
	while (i < ph.philo_num)
	{
		pthread_create(&(ph.philos[i]), NULL, philo_routine, &attrs[i]);
		i++;
	}
	i = 0;
	while (i < ph.philo_num)
		pthread_join(ph.philos[i++], NULL);
	ph_destroy(&ph);
}
