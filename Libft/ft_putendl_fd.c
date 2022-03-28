/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaegan <smaegan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:04:20 by smaegan           #+#    #+#             */
/*   Updated: 2021/10/21 18:21:10 by smaegan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	c;

	if (!s)
		return ;
	c = '\n';
	write(fd, s, ft_strlen(s));
	write(fd, &c, 1);
}
