/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:24:07 by kstallen       #+#    #+#                */
/*   Updated: 2019/11/08 12:14:29 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *string1;
	unsigned char *string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while ((*string1 != '\0' || *string2 != '\0') && n)
	{
		if (*string1 != *string2)
			return ((int)*string1 - (int)*string2);
		string1++;
		string2++;
		n--;
	}
	return (0);
}
