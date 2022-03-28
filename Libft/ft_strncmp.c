/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:31:40 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/19 16:56:05 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (*c1 == *c2 && *c1 && *c2 && n > 1)
	{
		c1++;
		c2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*c1 - *c2);
}
