/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:08:17 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/21 17:57:56 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long		i;
	char		buf;
	long		n2;

	n2 = n;
	i = 10;
	buf = '-';
	if (n2 < 0)
	{
		n2 *= -1;
		write(fd, &buf, 1);
	}
	while (n2 / i > 0)
		i *= 10;
	i /= 10;
	while (i > 0)
	{
		buf = n2 / i % 10 + 48;
		write(fd, &buf, 1);
		i /= 10;
	}
}
