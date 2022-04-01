/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:44:13 by smaegan           #+#    #+#             */
/*   Updated: 2022/04/01 18:04:29 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_buf_mandatory(unsigned long int nbr, char *str, t_buf *buf)
{
	int	n1;

	n1 = 0;
	if (nbr >= 16)
		n1 += ft_putptr_buf_mandatory(nbr / 16, str, buf);
	else
	{
		n1 += 2;
		buf->i += 2;
		buf_check(buf);
		buf->buf[buf->i - 2] = '0';
		buf->buf[buf->i - 1] = 'x';
	}
	n1++;
	buf->buf[buf->i] = str[nbr % 16];
	buf->i++;
	return (n1);
}

size_t	ft_putnbr_base_fd(int fd, unsigned long int nbr,
				unsigned long base, char *symbols)
{
	unsigned long			i;
	char					buf;
	unsigned long			n2;
	size_t					n1;

	n1 = 0;
	n2 = (unsigned long) nbr;
	i = (unsigned long) base;
	while (n2 / i > 16)
		i *= base;
	if (n2 / i == 0)
		i /= base;
	while (i > 0)
	{
		buf = symbols[n2 / i % base];
		write(fd, &buf, 1);
		n1++;
		i /= base;
	}
	return (n1);
}

size_t	ft_putulong_base_buf(unsigned int nbr,
						unsigned long base, char *symbols, t_buf *buf)
{
	int	n;

	n = 0;
	if (nbr >= base)
		n += ft_putulong_base_buf(nbr / base, base, symbols, buf);
	n++;
	buf_check(buf);
	buf->buf[buf->i] = symbols[nbr % base];
	buf->i++;
	return (n);
}
