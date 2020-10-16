/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_lu.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:59:49 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 14:03:53 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int		lulen(long unsigned nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	print_lu(t_data *data)
{
	int		len;
	int		field_width;
	char	fill;

	fill = data->flag_zero && (data->precision < 0) ? '0' : ' ';
	len = lulen(data->arg.lu);
	field_width = data->width > data->precision ?
	data->width : data->precision;
	data->precision = data->precision > len ?
		data->precision : len;
	while (field_width > data->precision)
	{
		putchar_printf(fill, data);
		field_width--;
	}
	while (field_width > len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_unsigned_printf(data->arg.lu, data);
}

void	print_lu_min(t_data *data)
{
	char	fill;
	int		len;
	int		field_width;

	field_width = data->width;
	fill = ' ';
	len = lulen(data->arg.lu);
	while (field_width + data->precision > data->width + len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_unsigned_printf(data->arg.lu, data);
	while (field_width > len)
	{
		putchar_printf(fill, data);
		field_width--;
	}
}
