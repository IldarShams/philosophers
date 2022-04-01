/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:52:12 by smaegan           #+#    #+#             */
/*   Updated: 2022/04/01 18:02:36 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#define ULONG_MAX 18446744073709551615

int	ft_putchar_buf(char c, t_buf *buf)
{
	buf->buf[buf->i] = c;
	buf->i++;
	return (1);
}

int	skip(const char **str, t_buf *buf)
{
	int	n;

	n = 0;
	if (*str != NULL)
	{
		while (**str != '\0' && **str != '%')
		{
			buf->buf[buf->i] = **str;
			(*str)++;
			n++;
			buf->i++;
		}
	}
	return (n);
}

int	spec_proc(const char **str, void *arg, t_buf *buf)
{
	int	n;

	n = 0;
	(*str)++;
	if (**str == 'd' || **str == 'i')
		n += ft_putnbr_buf_mandatory((int)arg, buf);
	else if (**str == 'c')
		n += ft_putchar_buf((char)arg, buf);
	else if (**str == 's')
		n += ft_putstr_buf((char *)arg, buf);
	else if (**str == 'p')
		n += ft_putptr_buf_mandatory((unsigned long int)arg,
				"0123456789abcdef", buf);
	else if (**str == 'u')
		n += ft_putunnbr_buf_mandatory((unsigned int)arg, buf);
	else if (**str == 'x')
		n += ft_putulong_base_buf((unsigned long int)arg,
				16, "0123456789abcdef", buf);
	else if (**str == 'X')
		n += ft_putulong_base_buf((unsigned long int)arg,
				16, "0123456789ABCDEF", buf);
	else
		n += ft_putchar_buf(**str, buf);
	(*str)++;
	return (n);
}

void	buf_check(t_buf *buf)
{
	if (buf->i >= buf->size)
		extend_buffer(buf);
}

void	extend_buffer(t_buf *buf)
{
	int		i;
	int		new_size;
	char	*temp;

	i = 0;
	if (buf == NULL && buf->buf != NULL)
		return ;
	new_size = (int)(buf->size * 2);
	temp = malloc(new_size);
	while (i < buf->size)
	{
		temp[i] = buf->buf[i];
		i++;
	}
	free(buf->buf);
	buf->buf = temp;
}

int	ft_printf(const char *str, ...)
{
	size_t	n;
	va_list	args;
	t_buf	buf;

	va_start(args, str);
	n = 0;
	if (str == NULL)
		return (0);
	buf.buf = malloc((int)(ft_strlen(str) * 1.5));
	buf.size = (int)(ft_strlen(str) * 1.5);
	buf.i = 0;
	while (*str != '\0')
	{
		n += skip(&str, &buf);
		if (*str != '\0')
			n += spec_proc(&str, va_arg(args, void *), &buf);
	}
	va_end(args);
	write(1, buf.buf, buf.i);
	free(buf.buf);
	return (n);
}
