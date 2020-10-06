/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:47:25 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 14:03:53 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	print_s(t_data *data)
{
	data->arg.vp = va_arg(data->var, char *);
	if (!data->arg.vp)
		data->arg.vp = "(null)";
	calc_field_width(data);
	if (data->flag_minus)
	{
		if (data->precision >= 0)
			putstr_printf(data->arg.vp, data->precision, data);
		else
			putstr_printf(data->arg.vp, ft_strlen(data->arg.vp), data);
	}
	print_width_ascii(data);
	if (!data->flag_minus)
	{
		if (data->precision >= 0 &&
		data->precision < (int)ft_strlen(data->arg.vp))
			putstr_printf(data->arg.vp, data->precision, data);
		else
			putstr_printf(data->arg.vp, ft_strlen(data->arg.vp), data);
	}
}

void	print_c(t_data *data)
{
	data->arg.c = va_arg(data->var, int);
	if (!data->flag_minus)
		print_width_ascii(data);
	putchar_printf(data->arg.li, data);
	if (data->flag_minus)
		print_width_ascii(data);
}

void	print_p(t_data *data)
{
	char	*string;

	data->arg.lu = va_arg(data->var, unsigned long);
	string = !data->arg.lu ? null_pointer(data) :
	ft_itoa_base_pointer(data->arg.lu, 16);
	if ((data->precision < (int)ft_strlen(string)) &&
		(data->width < (int)ft_strlen(string) || data->flag_minus))
	{
		putstr_printf(string, ft_strlen(string), data);
		printf_width_pointer(data);
	}
	else
	{
		printf_width_pointer(data);
		putstr_printf(string, ft_strlen(string), data);
	}
		free(string);
}

void	print_per(t_data *data)
{
	data->width -= 1;
	if (!data->flag_minus)
		print_width_ascii(data);
	putchar_printf('%', data);
	if (data->flag_minus)
		print_width_ascii(data);
}

void	print_width_ascii(t_data *data)
{
	char	fill;

	fill = ' ';
	if (data->flag_zero && !data->flag_minus)
		fill = '0';
	if (data->type == 'c')
		data->width--;
	while (data->width > 0)
	{
		putchar_printf(fill, data);
		data->width--;
	}
}

void	*null_pointer(t_data *data)
{
	int		size;
	int		null_len;
	char	*ptr;

	null_len = data->precision > 0 ? data->precision : 0;
	null_len = data->precision < 0 ? 1 : 0;
	size = data->precision > 3 ? data->precision : 4;
	ptr = malloc(size);
	ptr[0] = '0';
	ptr[1] = 'x';
	if (null_len)
		ft_memset(&ptr[2], '0', null_len);
	if (data->precision < 0)
		ptr[3] = '\0';
	else
		ptr[size] = '\0';
	return (ptr);
}
