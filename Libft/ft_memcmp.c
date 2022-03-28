/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:30:50 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/13 14:52:09 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (c1[i] != c2[i])
		{
			return (c1[i] - c2[i]);
		}
		i++;
		n--;
	}
	return (0);
}
