/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/03 14:08:28 by kstallen      #+#    #+#                 */
/*   Updated: 2020/08/26 16:03:47 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

/*
** Receives arguments, declares and initiates variable argument list
** and parses format string. Returns int: n chars printed or neg if error.
** Errors: [-1 = no format string][-2 = '%' found at end of format string]
*/

int		ft_fprintf(int fd, const char *format, ...)
{
	t_data	data;

	if (format == NULL)
		return (-1);
	ft_bzero(&data, sizeof(data));
	reset_struct(&data);
	data.format = format;
	data.fd = fd;
	va_start(data.var, format);
	while (data.format[data.i])
	{
		if (data.format[data.i] == '%')
		{
			if (data.format[data.i + 1] == '\0')
				return (-2);
			else
				populate_execute_struct(&data);
		}
		else if (data.format[data.i != '%'])
			putchar_printf(data.format[data.i], &data);
		data.i++;
	}
	return (data.char_count);	
}