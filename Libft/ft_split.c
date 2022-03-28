/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:53:01 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/21 18:33:06 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_num_words(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	if (!s)
		return (0);
	while (1)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			n++;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (s[i] == '\0')
			break ;
	}
	return (n);
}

char	*get_word(char const *s, int i, char c)
{
	int		size;
	int		j;
	char	*word;

	j = i;
	size = 0;
	if (!s)
		return (NULL);
	while (s[j] != '\0' && s[j] != c)
	{
		size++;
		j++;
	}
	word = malloc(size + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

void	free_res(char **res, int i)
{
	int	j;

	j = 0;
	if (!res)
		return ;
	while (j < i)
	{
		free(res[j]);
		j++;
	}
	free(res);
}

int	skip(char const *s, char c, int i, int mode)
{
	if (!s)
		return (0);
	if (mode == 0)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	else
	{
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;

	k = 0;
	i = 0;
	res = (char **)malloc(sizeof(char *) * (get_num_words(s, c) + 1));
	if (res == NULL || s == NULL)
		return (NULL);
	while (1)
	{
		i = skip(s, c, i, 0);
		if (s[i] == '\0')
			break ;
		if (s[i] != '\0')
			res[k] = get_word(s, i, c);
		if (res[k++] == NULL)
		{
			free_res(res, --k);
			return (NULL);
		}
		i = skip(s, c, i, 1);
	}
	res[k] = NULL;
	return (res);
}
