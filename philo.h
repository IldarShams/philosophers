/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:03:03 by smaegan           #+#    #+#             */
/*   Updated: 2022/03/28 19:07:21 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include "./Libft/libft.h"

typedef struct s_philo
{
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				philo_num;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				eat_num;
	int				prog_state;
	t_philo_attr	*attrs;
}	t_philo;

typedef struct s_philo_attr
{
	int				philo_num;
	int				starve_time;
}	t_philo_attr;

int	ph_init(int argc, char **argv, t_philo *ph);

#endif
