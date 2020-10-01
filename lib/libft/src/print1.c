/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:41:59 by kstallen      #+#    #+#                 */
/*   Updated: 2020/08/26 16:03:47 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	print_di(t_data *data)
{
	data->arg.li = va_arg(data->var, int);
	if (data->arg.li == 0)
		print_di_null(data);
	calc_field_width(data);
	if (data->flag_minus && data->arg.li > 0)
		print_di_min(data);
	else if (data->flag_zero && !data->flag_minus && 
	data->precision == -1 && data->arg.li != 0)
		print_di_zero(data);
	else if (data->flag_minus && data->arg.li < 0)
		print_di_min_neg(data);
	else if (!data->flag_minus && data->arg.li > 0)
		print_di_reg(data);
	else if (!data->flag_minus && data->arg.li < 0)
	{
		if (data->flag_zero && data->precision < 0)
			print_di_neg_zero(data);
		else if (data->precision >= data->width)
			print_di_neg_prec(data);
		else
			print_di_neg(data);
	}
	else if (!data->flag_minus && data->arg.li < 0)
		print_di_neg(data);
}

void	print_u(t_data *data)
{
	data->arg.lu = va_arg(data->var, unsigned int);
	// if (data->arg.lu < 0)
	// 	data->arg.lu *= -1;
	if (data->arg.lu == 0)
		print_di_null(data);
	else if (data->flag_minus)
		print_lu_min(data);
	else
		print_lu(data);
}

void	print_hex(t_data *data)
{
	data->arg.lu = va_arg(data->var, unsigned long);
	if (data->type == 'x')
		data->arg.vp = ft_itoa_base(data->arg.lu, 16, 'a');
	else if (data->type == 'X')
		data->arg.vp = ft_itoa_base(data->arg.lu, 16, 'A');
	if (data->flag_minus)
		print_hexadecimal_min(data);
	else
		print_hexadecimal(data);
	free(data->arg.vp);
}
