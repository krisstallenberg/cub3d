/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:02:22 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 14:03:53 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

/*
** Resets data in struct related to individual arguments.
** Retains format string, va_list, i and char_count.
*/

void	reset_struct(t_data *data)
{
	data->flag_zero = 0;
	data->flag_minus = 0;
	data->width = -1;
	data->precision = -1;
	data->type = 0;
}

/*
** Returns the length of an integer.
*/

int		intlen(int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

/*
** Returns char string conversion of unsigned long with base,
** free return value [!]
*/

char	*ft_itoa_base(unsigned long value, int base, char c)
{
	char	*s;
	long	n;
	int		sign;
	int		i;

	n = value;
	sign = 0;
	i = 1;
	n /= base;
	while (n)
	{
		n /= base;
		i++;
	}
	s = (char*)ft_memmalloc(sizeof(char) * (i + 1));
	n = value;
	while (i + sign)
	{
		i--;
		s[i] = (n % base < 10) ? n % base + '0' : n % base + c - 10;
		n /= base;
	}
	i--;
	i == 0 ? s[i] = '-' : 0;
	return (s);
}

/*
** Returns char string conversion (with "0x0" prefix) of unsigned long
** with base, free return value [!]
*/

char	*ft_itoa_base_pointer(unsigned long value, int base)
{
	char			*s;
	int				i;
	unsigned long	n;

	i = 0;
	n = value;
	while (n)
	{
		n /= base;
		i++;
	}
	s = malloc(sizeof(char) * (i + 3));
	i += 2;
	s[i] = '\0';
	i--;
	while (value)
	{
		s[i] = (value % base < 10) ? value % base + '0' :
			value % base + 'a' - 10;
		value /= base;
		i--;
	}
	s[i] = 'x';
	s[i - 1] = '0';
	return (s);
}

void	*ft_memmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}
