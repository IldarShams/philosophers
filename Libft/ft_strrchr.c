/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:32:00 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/23 15:03:29 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	c = c % 128;
	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] != '\0')
		{
			j = i + 1;
			while (s[j] != '\0' && s[j] != c)
				j++;
			if (s[j] == c)
				i = j;
		}
		else
			break ;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return ((void *)0);
}
