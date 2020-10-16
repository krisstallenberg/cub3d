/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:46:46 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/01 13:40:49 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*string;
	int		length;

	string = (char *)str;
	length = ft_strlen(string);
	string += length;
	while (length >= 0)
	{
		if (*string == (char)c)
			return (string);
		string--;
		length--;
	}
	return (NULL);
}
