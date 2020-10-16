/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:29:19 by kstallen       #+#    #+#                */
/*   Updated: 2019/12/11 15:27:10 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t lensrc;

	if (src == 0)
		return (0);
	lensrc = ft_strlen(src);
	if (lensrc + 1 < size)
	{
		ft_memcpy(dst, src, lensrc + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (lensrc);
}
