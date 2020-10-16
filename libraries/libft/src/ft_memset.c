/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:52:41 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/07 13:21:42 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (i < (int)len)
	{
		((char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
