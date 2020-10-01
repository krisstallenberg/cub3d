/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 12:09:30 by kstallen      #+#    #+#                 */
/*   Updated: 2019/11/25 12:09:32 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		lens1;
	int		lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (newstr == NULL)
		return (NULL);
	ft_memcpy(newstr, s1, lens1 + 1);
	ft_strlcat(newstr, s2, lens1 + lens2 + 1);
	return (newstr);
}
