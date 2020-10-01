/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 12:54:50 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/15 20:45:08 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;
	char *ls;
	char *ld;

	if (dst == NULL && src == NULL)
		return (dst);
	d = dst;
	s = (char *)src;
	if (d < s)
		ft_memcpy(dst, src, len);
	else
	{
		ls = s + (len - 1);
		ld = d + (len - 1);
		while (len)
		{
			*ld = *ls;
			ld--;
			ls--;
			len--;
		}
	}
	return (dst);
}
