/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:53:35 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/13 12:39:38 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int		i;
	void				*p;
	char				*c;

	i = 0;
	p = malloc(size * count);
	if (p == 0)
		return (p);
	c = p;
	while (count * size > i)
	{
		*c++ = 0;
		i++;
	}
	return (p);
}
