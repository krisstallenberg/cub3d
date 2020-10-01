/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:46:46 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/08 18:41:50 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	char	*string;
	int		length;

	string = (char *)str;
	length = ft_strlen(string);
	while (length >= 0)
	{
		if (*string == (char)c)
			return (string);
		string++;
		length--;
	}
	return (NULL);
}
