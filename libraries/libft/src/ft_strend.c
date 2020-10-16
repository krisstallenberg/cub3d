/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strend.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 13:17:34 by kris          #+#    #+#                 */
/*   Updated: 2020/09/16 13:27:55 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_strend(char *str, char *end)
{
    int len;

    len = ft_strlen(end);
    while (*str)
        str++;
    while (*end)
        end++;
    while (len)
    {
        if (*str != *end)
            return (0);
        str--;
        end--;
        len--;
    }
    return (1);
}
