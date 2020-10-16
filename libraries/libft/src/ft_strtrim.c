/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 12:00:32 by kstallen      #+#    #+#                 */
/*   Updated: 2019/11/30 12:00:33 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(s1) - i;
	if (len != 0)
		while (s1[i + len - 1] && ft_strchr(set, s1[i + len - 1]) != NULL)
			len--;
	return (ft_substr(s1, i, len));
}
