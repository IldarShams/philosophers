/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:03:03 by smaegan           #+#    #+#             */
/*   Updated: 2022/04/01 18:48:50 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include "./Libft/libft.h"
# include "./ft_printf_buf_without_flags/ft_printf.h"

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
	int				*eat_and_sleep;
	struct timeval	prog_start_time;
}	t_philo;

typedef struct s_philo_attr
{
	int				id;
	int				starve_time;
	int				eat_num;
	t_philo			*ph;
}	t_philo_attr;

int		ph_init(int argc, char **argv, t_philo *ph);
int		attrs_destroy(t_philo_attr **attrs);
int		ph_destroy(t_philo *ph);
int		msg(t_philo_attr *attr, int type);
void	psleep(t_philo_attr *attr);
void	think(t_philo_attr *attr);
void	eat(t_philo_attr *attr);
void	*philo_routine(void *arg);
int		attrs_init(t_philo_attr **attrs, t_philo *ph);
int		check_e_and_s(t_philo_attr *attr);

#endif
