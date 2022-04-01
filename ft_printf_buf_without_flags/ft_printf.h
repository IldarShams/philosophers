/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:14:24 by smaegan           #+#    #+#             */
/*   Updated: 2022/04/01 18:06:24 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_buf
{
	char	*buf;
	int		size;
	int		i;
}	t_buf;

//mandatory
int		ft_printf(const char *str, ...);
//
int		ft_putstr_buf(char *s, t_buf *buf);
int		ft_putunnbr_buf_mandatory(unsigned int n, t_buf *buf);
int		ft_putnbr_buf_mandatory(int n, t_buf *buf);
int		check_max_long(unsigned long int nbr);
int		ft_putptr_buf_mandatory(unsigned long int nbr, char *str, t_buf *buf);
size_t	ft_strlen(const char *s);
size_t	ft_putulong_base_buf(unsigned int nbr,
			unsigned long base, char *symbols, t_buf *buf);
int		ft_putchar_buf(char c, t_buf *t_buf);
int		spec_proc(const char **str, void *arg, t_buf *buf);
void	buf_check(t_buf *buf);
void	extend_buffer(t_buf *buf);

#endif
