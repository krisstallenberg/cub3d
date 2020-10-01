/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 09:58:22 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/17 18:11:25 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char ch;

	if (dst == src)
		return (dst);
	ch = (unsigned char)c;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n)
	{
		*d = *s;
		if (*s == ch)
			return (d + 1);
		d++;
		s++;
		n--;
	}
	return (NULL);
}
