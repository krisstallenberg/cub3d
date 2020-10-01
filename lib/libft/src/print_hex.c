/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:53:13 by kstallen      #+#    #+#                 */
/*   Updated: 2020/08/26 16:03:47 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	print_hexadecimal(t_data *data)
{
	int		len;
	int		field_width;
	char	fill;

	fill = data->flag_zero && (data->precision < 0) ? '0' : ' ';
	len = ft_strlen(data->arg.vp);
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
	putstr_printf(data->arg.vp, len, data);
}

void	print_hexadecimal_min(t_data *data)
{
	char	fill;
	int		len;
	int		field_width;

	field_width = data->width;
	fill = ' ';
	len = ft_strlen(data->arg.vp);
	while (field_width + data->precision > data->width + len)
	{
		putchar_printf('0', data);
		field_width--;
	}
	putstr_printf(data->arg.vp, len, data);
	while (field_width > len)
	{
		putchar_printf(fill, data);
		field_width--;
	}
}

void	printf_width_pointer(t_data *data)
{
	char	fill;
	int		len;

	fill = ' ';
	if (data->type == 'd' || data->type == 'i')
		len = intlen(data->arg.li);
	if (data->type == 'x' || data->type == 'X')
		len = ft_strlen(ft_itoa_base(data->arg.lu, 16, 'a'));
	if (data->precision > len && !data->flag_zero)
		fill = '0';
	if (data->flag_zero && !data->flag_minus &&
	!(data->precision >= 0))
		fill = '0';
	while (data->width > len)
	{
		putchar_printf(fill, data);
		len++;
	}
}
