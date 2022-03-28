/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:40 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/23 16:08:26 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*p;
	char			c2;

	c2 = (char)c;
	p = (char *)s;
	while (n > 0)
	{
		if (*p == c2)
			return (p);
		p++;
		n--;
	}
	return ((void *)0);
}
