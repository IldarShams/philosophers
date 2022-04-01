/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_puts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:27:55 by smaegan           #+#    #+#             */
/*   Updated: 2022/04/01 17:57:30 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putnbr_buf_mandatory(int n, t_buf *buf)
{
	int	n1;

	n1 = 0;
	if (n < 0)
	{
		n = -n;
		buf_check(buf);
		buf->buf[buf->i] = '-';
		buf->i++;
		n1++;
	}		
	if (n / 10 > 0)
		n1 += ft_putnbr_buf_mandatory(n / 10, buf);
	buf_check(buf);
	buf->buf[buf->i] = n % 10 + 48;
	buf->i++;
	n1++;
	return (n1);
}

int	ft_putstr_buf(char *s, t_buf *buf)
{
	int	i;
	int	n;

	i = 0;
	if (!s)
		s = "(null)";
	n = ft_strlen(s);
	while (i < n)
	{
		buf->buf[buf->i] = s[i];
		i++;
		buf->i++;
	}
	return (n);
}

int	ft_putunnbr_buf_mandatory(unsigned int n, t_buf *buf)
{
	int	n1;

	n1 = 0;
	if (n / 10 > 0)
		n1 += ft_putunnbr_buf_mandatory(n / 10, buf);
	buf_check(buf);
	buf->buf[buf->i] = n % 10 + 48;
	buf->i++;
	n1++;
	return (n1);
}
