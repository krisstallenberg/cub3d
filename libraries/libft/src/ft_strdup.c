/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/24 16:12:40 by kstallen      #+#    #+#                 */
/*   Updated: 2019/11/24 16:12:44 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, len);
	s2[len] = '\0';
	return (s2);
}
