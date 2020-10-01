/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_di.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:58:49 by kstallen      #+#    #+#                 */
/*   Updated: 2020/08/26 16:03:47 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	print_di_reg(t_data *data)
{
	int		len;
	int		field_width;
	char	fill;

	fill = data->flag_zero && data->precision < 0 ? '0' : ' ';
	len = intlen(data->arg.li);
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
	putnbr_printf(data->arg.li, data);
}

void	print_di_zero(t_data *data)
{
	int	len;
	
	len = intlen(data->arg.li);
	data->arg.li < 0 ? putchar_printf('-', data) : 0;
	while (data->width > len)
		{
			putchar_printf('0', data);
			data->width--;
		}
	data->arg.li < 0 ? putnbr_printf(-data->arg.li, data) :
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg_zero(t_data *data)
{
	int		len;
	int		field_width;

	data->arg.li *= -1;
	len = intlen(data->arg.li) > data->precision ?
		intlen(data->arg.li) : data->precision;
	field_width = data->width - 1;
	if (data->precision >= data->width)
	{
		print_di_neg_zero_prec(data);
		return ;
	}
	putchar_printf('-', data);
	while (field_width > len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	while (field_width > intlen(data->arg.li))
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg_zero_prec(t_data *data)
{
	int		len;

	len = intlen(data->arg.li);
	putchar_printf('-', data);
	while (data->precision > len)
	{
		putchar_printf('0', data);
		data->precision--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg(t_data *data)
{
	int		len;
	int		field_width;


	if (data->arg.li == -2147483648)
		data->arg.li = 2147483648;
	else
		data->arg.li *= -1;
	len = intlen(data->arg.li) > data->precision ?
		intlen(data->arg.li) : data->precision;
	field_width = data->width - 1;
	while (field_width > len)
	{
		putchar_printf(' ', data);
		field_width--;
	}
	putchar_printf('-', data);
	while (field_width > intlen(data->arg.li))
	{
		putchar_printf('0', data);
		field_width--;
	}
	putnbr_printf(data->arg.li, data);
}

void	print_di_neg_prec(t_data *data)
{
	int		len;

	len = intlen(data->arg.li);
	data->arg.li *= -1;
	putchar_printf('-', data);
	while (data->precision > len - 1)
	{
		putchar_printf('0', data);
		data->precision--;
	}
	putnbr_printf(data->arg.li, data);
}
