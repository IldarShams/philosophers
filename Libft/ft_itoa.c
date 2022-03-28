/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:25:38 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/21 17:52:10 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*get_arr(long n2, long i, int size, int sign)
{
	char	*res;

	res = malloc(size + 1);
	if (res == NULL)
		return (NULL);
	size = 0;
	if (sign == -1)
		res[size++] = '-';
	while (i > 0)
	{
		res[size] = (n2 / i % 10) + 48;
		size++;
		i /= 10;
	}
	res[size] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	long		i;
	int			sign;
	char		*res;
	int			size;
	long		n2;

	n2 = n;
	size = 1;
	sign = 1;
	i = 10;
	if (n2 < 0)
	{
		n2 *= -1;
		sign = -1;
		size++;
	}
	while (n2 / i > 0)
	{
		i *= 10;
		size++;
	}
	i /= 10;
	res = get_arr(n2, i, size, sign);
	return (res);
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
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		char *res = ft_itoa(0);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 2)
// 	{
// 		char *res = ft_itoa(9);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 3)
// 	{
// 		char *res = ft_itoa(-9);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 4)
// 	{
// 		char *res = ft_itoa(10);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 5)
// 	{
// 		char *res = ft_itoa(-10);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 6)
// 	{
// 		char *res = ft_itoa(8124);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 7)
// 	{
// 		char *res = ft_itoa(-9874);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 8)
// 	{
// 		char *res = ft_itoa(543000);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 9)
// 	{
// 		char *res = ft_itoa(-2147483648LL);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	else if (arg == 10)
// 	{
// 		char *res = ft_itoa(2147483647);
// 		ft_print_result(res);
// 		free(res);
// 	}
// 	return (0);
// }
