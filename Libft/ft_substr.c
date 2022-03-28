/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:16:58 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/23 15:53:33 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <unistd.h>

unsigned int	get_size(char const *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ss;
	unsigned int		i;
	int					j;

	if (!s)
		return (NULL);
	i = start;
	if (start > get_size(s))
	{
		ss = malloc(1);
		if (ss)
			ss[0] = '\0';
		return (ss);
	}
	j = 0;
	if (len > get_size(s + start))
		len = get_size(s + start);
	ss = malloc(len + 1);
	if (ss != NULL)
	{
		while (i < len + start)
			ss[j++] = s[i++];
		ss[j] = '\0';
	}
	return (ss);
}

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int main(int argc, const char *argv[])
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	char	*strsub;
// 	int		arg;

// 	alarm(5);
// 	if (argc == 1)
// 		return (0);
// 	else if ((arg = atoi(argv[1])) == 1)
// 	{
// 		if (!(strsub = ft_substr(str, 0, 10)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 2)
// 	{
// 		if (!(strsub = ft_substr(str, 7, 10)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 3)
// 	{
// 		if (!(strsub = ft_substr(str, 7, 0)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 4)
// 	{
// 		if (!(strsub = ft_substr(str, 0, 0)))
// 			ft_print_result("NULL");
// 		else
// 			ft_print_result(strsub);
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	else if (arg == 5)
// 	{
// 		char *bullshit;
// 		if (!(strsub = ft_substr(str, 400, 20)))
// 			ft_print_result("NULL");
// 		else
// 		{
// 			bullshit = (char *)&strsub[30];
// 			bullshit = "FULL BULLSHIT";
// 			if (strsub)
// 				ft_print_result(strsub);
// 			else
// 				ft_print_result("rip");
// 		}
// 		if (str == strsub)
// 			ft_print_result("\nA new string was not returned");
// 	}
// 	return (0);
// }
