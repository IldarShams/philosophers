/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:31:03 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/19 15:54:43 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst2;
	const char	*src2;

	src2 = src;
	dst2 = dst;
	if ((dst == NULL && src == NULL) || n <= 0)
		return (dst);
	while (n > 0)
	{
		*dst2 = *src2;
		dst2++;
		src2++;
		n--;
	}
	return (dst);
}
