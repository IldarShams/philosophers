/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:44:14 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/19 18:28:15 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	char	*rets;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size1 = 0;
	size2 = 0;
	while (s1[size1] != '\0')
		size1++;
	while (s2[size2] != '\0')
		size2++;
	rets = malloc(size1 + size2 + 1);
	if (rets == NULL)
		return (NULL);
	while (*s1 && rets)
		rets[i++] = *s1++;
	while (*s2 && rets)
		rets[i++] = *s2++;
	if (rets)
		rets[i] = '\0';
	return (rets);
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
// 	char	s1[] = "lorem ipsum";
// 	char	s2[] = "dolor sit amet";
// 	char	*strjoin;
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (!(strjoin = ft_strjoin(s1, s2)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strjoin);
// 		if (strjoin == s1 || strjoin == s2)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 2)
// 	{
// 		s1[0] = '\0';
// 		if (!(strjoin = ft_strjoin(s1, s2)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strjoin);
// 		if (strjoin == s1 || strjoin == s2)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 3)
// 	{
// 		s2[0] = '\0';
// 		if (!(strjoin = ft_strjoin(s1, s2)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strjoin);
// 		if (strjoin == s1 || strjoin == s2)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 4)
// 	{
// 		s1[0] = '\0';
// 		s2[0] = '\0';
// 		if (!(strjoin = ft_strjoin(s1, s2)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strjoin);
// 		if (strjoin == s1 || strjoin == s2)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	return (0);
// }
