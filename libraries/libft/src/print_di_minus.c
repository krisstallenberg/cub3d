/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_di_minus.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:57:35 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 14:03:53 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	print_di_min(t_data *data)
{
	char	fill;
	int		len;
	int		field_width;

	field_width = data->width;
	fill = ' ';
	len = intlen(data->arg.li);
	while (field_width + data->precision > data->width + len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
	while (field_width > len)
	{
		putchar_printf(fill, data);
		field_width--;
	}
}

void	print_di_min_neg(t_data *data)
{
	int		len;
	int		field_width;

	field_width = 0;
	data->arg.li *= -1;
	len = intlen(data->arg.li);
	putchar_printf('-', data);
	while (field_width < data->precision - len)
	{
		putchar_printf('0', data);
		field_width++;
	}
	putnbr_printf(data->arg.li, data);
	while (field_width < data->width - len - 1)
	{
		putchar_printf(' ', data);
		field_width++;
	}
}

void	print_null_num(t_data *data, int field_width)
{
	if (data->precision == 0)
	{
		putchar_printf(' ', data);
		field_width--;
	}
	else if (field_width > 0)
	{
		putnbr_printf(data->arg.li, data);
		field_width--;
	}
}

void	print_di_null(t_data *data)
{
	int		field_width;
	char	fill;

	if (data->width == 0 && data->precision == 0)
		return ;
	fill = data->flag_zero && data->precision < 0 ? '0' : ' ';
	field_width = data->width > data->precision ?
		data->width : data->precision;
	field_width = field_width > 1 ? field_width : 1;
	if (data->flag_minus)
	{
		print_di_null_minus(data);
		return ;
	}
	while (field_width > data->precision && field_width > 1)
	{
		putchar_printf(fill, data);
		field_width--;
	}
	while (field_width > 1)
	{
		putchar_printf('0', data);
		field_width--;
	}
	print_null_num(data, field_width);
}

void	print_di_null_minus(t_data *data)
{
	int		field_width;
	char	fill;

	fill = data->flag_zero && data->precision < 0 ? '0' : ' ';
	field_width = data->width;
	while (field_width > (data->width - data->precision + 1))
	{
		putchar_printf('0', data);
		field_width--;
	}
	print_null_num(data, field_width);
	while (field_width > 1)
	{
		putchar_printf(fill, data);
		field_width--;
	}
}
// (field_width + data->precision > data->width - 1)