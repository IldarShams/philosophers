/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:31:27 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/19 16:34:28 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	dstsize2;

	j = 0;
	i = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	size = i;
	dstsize2 = i;
	while (src[j] != '\0')
		j++;
	size += j;
	if (i == dstsize)
		return (size);
	j = 0;
	while (dstsize - 1 > i && src[j] != '\0')
		dst[i++] = src[j++];
	if (dstsize != 0 && dstsize2 <= dstsize)
		dst[i] = '\0';
	return (size);
}

// void	ft_print_result(int n)
// {
// 	char	c;

// 	if (n >= 10)
// 		ft_print_result(n / 10);
// 	c = n % 10 + '0';
// 	write (1, &c, 1);
// }

// int	main(void)
// {
// 	char	*dest;

// 	memset(dest, 'r', 15);
// 	ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// }

// int main(void)
// {
//     char s1[15]="1234567890";
//     char s2[15]="1234567890";
//     memset(s1, 'r', 15);
//     memset(s2, 'r', 15);
//     printf("%lu\n", strlcat(s1, "lorem ipsum dolor sit amet", 5));
//     printf("%s\n", s1);
//     printf("%lu\n", ft_strlcat(s2, "lorem ipsum dolor sit amet", 5));
//     printf("%s\n", s2);
//     return 0;
// }
