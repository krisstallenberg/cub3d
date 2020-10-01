/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:47:52 by kstallen      #+#    #+#                 */
/*   Updated: 2020/08/26 16:03:47 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/*
** Initializes function-pointer struct and redirects to correct printing funct.
*/

void	select_printer(t_data *data)
{
	int					j;
	static t_function	function_pointer[9] = {
		{'%', print_per},
		{'d', print_di},
		{'i', print_di},
		{'u', print_u},
		{'x', print_hex},
		{'X', print_hex},
		{'s', print_s},
		{'c', print_c},
		{'p', print_p}
	};

	j = 0;
	data->type = data->format[data->i];
	while (j < (int)(sizeof(function_pointer) / sizeof(t_function)))
	{
		if (function_pointer[j].type == data->type)
			(function_pointer[j].print)(data);
		j++;
	}
}

/*
** Populates the width and precision in struct.
** If '.' is given, but no precision is specified, precision == 0.
** Default values are -1 for width and -1 for precision.
*/

void	pop_width(t_data *data)
{
	if (data->format[data->i] == '*')
	{
		data->width = va_arg(data->var, int);
		if (data->width < 0)
		{
			data->flag_minus = 1;
			data->width *= -1;
		}
		data->i++;
	}
	else if (ft_atoi(&data->format[data->i]) >= 0)
		data->width = ft_atoi(&data->format[data->i]);
	while (data->format[data->i] >= '0' && data->format[data->i] <= '9')
		data->i++;
}

void	pop_precision(t_data *data)
{
	if (data->format[data->i] == '.')
	{
		data->precision = 0;
		data->i++;
		if (data->format[data->i] == '*')
		{
			data->precision = va_arg(data->var, int);
			data->i++;
			return ;
		}
		if (ft_atoi(&data->format[data->i]) >= 0)
			data->precision = ft_atoi(&data->format[data->i]);
		while (data->format[data->i] >= '0' && data->format[data->i] <= '9')
			data->i++;
	}
}

/*
** Iterates over all '0' and '-' characters and populates flags in stuct.
*/

void	pop_flag(t_data *data)
{
	while (data->format[data->i] == '0' || data->format[data->i] == '-')
	{
		if (data->format[data->i] == '0')
			data->flag_zero = 1;
		if (data->format[data->i] == '-')
			data->flag_minus = 1;
		data->i++;
	}
}

int		is_specifier(char c)
{
	if (c == 's' || c == 'c' || c == 'p' || c == 'u' || c == 'x' || c == 'X' ||
		c == 'd' || c == 'i' || c == '%')
		return (1);
	else
		return (0);
}

/*
** Populates struct for every variable argument to print.
** Once printed, resets values of variable argument.
*/

void	populate_execute_struct(t_data *data)
{
	data->i++;
	pop_flag(data);
	pop_width(data);
	pop_precision(data);
	if (!(is_specifier(data->format[data->i])))
	{
		while (data->format[data->i] != '%')
			data->i--;
		data->i++;
		reset_struct(data);
		return ;
	}
	select_printer(data);
	reset_struct(data);
}
