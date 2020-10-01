/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:02:13 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/17 16:54:32 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		ch;
	const unsigned char	*str;

	str = s;
	ch = c;
	while (n)
	{
		if (*str == ch)
			return ((void *)str);
		str++;
		n--;
	}
	return (NULL);
}
