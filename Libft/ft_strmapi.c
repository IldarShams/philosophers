/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:43:21 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/21 18:21:46 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	res = malloc(size + 1);
	if (res != NULL)
	{
		while (i < size)
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
