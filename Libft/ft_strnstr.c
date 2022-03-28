/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:31:55 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/23 15:21:42 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (len > i)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && needle[j] != '\0'
			&& haystack[k] != '\0' && len > j && len > k)
		{
			j++;
			k++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		if (haystack[i] == '\0')
			break ;
		i++;
	}
	return ((void *)0);
}

// int main()
// {
// 	char haystack[30] = "aaabcabcd";
// 	char needle[10] = "aabc";

//     printf("%s\n", ft_strnstr(haystack, needle, -1));
//    // printf("%s\n", strnstr(haystack, needle, -1));
// }
