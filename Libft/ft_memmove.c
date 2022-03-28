/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:51:14 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/19 15:48:51 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst2;
	char	*src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	if (!dst && !src)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	}
	else
	{
		while (len > 0)
		{
			*dst2++ = *src2++;
			len--;
		}
	}
	return (dst);
}
