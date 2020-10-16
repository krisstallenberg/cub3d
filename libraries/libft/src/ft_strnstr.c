/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:40:13 by kstallen       #+#    #+#                */
/*   Updated: 2019/12/10 15:51:06 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;

	if (!*needle)
		return ((char *)haystack);
	needlen = ft_strlen(needle);
	if (needlen > len)
		return (NULL);
	while (*haystack && needlen <= len)
	{
		if (!ft_strncmp((char *)haystack, needle, needlen))
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
