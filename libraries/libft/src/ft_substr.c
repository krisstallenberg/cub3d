/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   substr.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 11:50:28 by kstallen      #+#    #+#                 */
/*   Updated: 2019/12/15 14:05:55 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
