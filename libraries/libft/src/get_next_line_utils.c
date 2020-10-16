/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/20 18:44:23 by kris          #+#    #+#                 */
/*   Updated: 2020/07/05 15:24:36 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = dst;
	s = src;
	while (n)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}

char	*ft_strchr(const char *str, int c)
{
	char	*string;
	int		length;

	string = (char *)str;
	length = ft_strlen(string);
	while (length >= 0)
	{
		if (string && *string == (char)c)
			return (string);
		string++;
		length--;
	}
	return (NULL);
}

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

void	*ft_memmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, size);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = ft_memmalloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s1, len);
	s2[len] = '\0';
	return (s2);
}
