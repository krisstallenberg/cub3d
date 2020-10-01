/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:03:13 by kstallen      #+#    #+#                 */
/*   Updated: 2020/08/26 16:03:47 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	putstr_printf(char *s, size_t len, t_data *data)
{
	len = ft_strlen(s) < len ? ft_strlen(s) : len;
	if (s)
	{
		write(data->fd, s, len);
		data->char_count += len;
	}
}

void	putchar_printf(char c, t_data *data)
{
	write(data->fd, &c, 1);
	data->char_count++;
}

void	putnbr_printf(int n, t_data *data)
{
	unsigned int s;

	s = n;
	if (s > 9)
		putnbr_printf(s / 10, data);
	putchar_printf((s % 10) + '0', data);
}

void	putnbr_unsigned_printf(unsigned int n, t_data *data)
{
	if (n > 9)
		putnbr_printf(n / 10, data);
	putchar_printf((n % 10) + '0', data);
}

void	calc_field_width(t_data *data)
{
	if (data->type == 'd' || data->type == 'i')
		data->width = data->width > intlen(data->arg.li) ?
			data->width : intlen(data->arg.li);
	if (data->type == 'x' || data->type == 'X')
	{
		data->width = data->width > intlen(data->arg.lu) ?
			data->width : intlen(data->arg.lu);
		data->width = data->width > data->precision ?
			data->width : data->precision;
	}
	if (data->type == 's')
	{
		if ((int)ft_strlen(data->arg.vp) > data->precision
			&& data->precision >= 0)
		{
			data->width -= data->precision < (int)ft_strlen(data->arg.vp) ?
				data->precision : (int)ft_strlen(data->arg.vp);
		}
		else
			data->width -= ft_strlen(data->arg.vp);
	}
}
