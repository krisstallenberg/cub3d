/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 14:35:31 by kstallen      #+#    #+#                 */
/*   Updated: 2019/12/15 13:36:09 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_parts(char const *s, char c)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static	int		len_next_c(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			break ;
		count++;
		s++;
	}
	return (count);
}

static void		array_free(char **array, int string)
{
	while (string)
	{
		string--;
		if (array[string])
			free(array[string]);
	}
	free(array);
}

static	char	**arraybuilder(char const *s, char c, char **array)
{
	int i;
	int currentlen;
	int	string;

	i = 0;
	string = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			currentlen = len_next_c(s + i, c);
			array[string] = ft_substr(s, i, currentlen);
			if (array[string] == NULL)
			{
				array_free(array, string);
				return (array);
			}
			string++;
			i += currentlen;
		}
		if (s[i])
			i++;
	}
	array[string] = NULL;
	return (array);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	int		parts;

	if (!s)
		return (NULL);
	parts = count_parts(s, c);
	array = (char **)malloc(sizeof(char *) * (parts + 1));
	if (!array)
		return (NULL);
	arraybuilder(s, c, array);
	return (array);
}
