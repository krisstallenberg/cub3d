/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/20 20:03:45 by kris          #+#    #+#                 */
/*   Updated: 2020/09/23 13:05:02 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_numlen(int number)
{
    int len;

    len = 0;
    if (number == 0)
        return (1);
    if (number < 0)
    {
        len++;
        number *= -1;
    }
    while (number)
    {
        number /= 10;
        len++;
    }
    return (len);
}
