/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:52:06 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/23 15:43:13 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_get_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	start = 0;
	while (s1[start] != '\0')
	{
		i = 0;
		while (set[i] != s1[start] && set[i] != '\0')
			i++;
		if (set[i] == s1[start])
			start++;
		else
			break ;
	}
	return (start);
}

int	ft_get_end(char const *s1, char const *set)
{
	int	i;
	int	end;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i--;
	end = i;
	while (end > 0)
	{
		i = 0;
		while (set[i] != s1[end] && set[i] != '\0')
			i++;
		if (set[i] == s1[end])
			end--;
		else
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	size_t	size;
	char	*s;
	int		end;

	if (s1 == NULL)
		return ((char *)s1);
	start = ft_get_start(s1, set);
	end = ft_get_end(s1, set);
	size = end - start + 1;
	if (end <= start)
	{
		s = malloc(1);
		if (s != NULL)
			s[0] = '\0';
		return (s);
	}
	s = ft_substr(s1, start, size);
	if (s == NULL)
	{
		s = malloc(1);
		if (s != NULL)
			s[0] = '\0';
	}
	return (s);
}

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(int argc, const char *argv[])
// {
// 	char *s = ft_strtrim("", "123");
// 	printf("%s", s);
// 	return (0);
// }
