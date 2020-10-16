/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fprintf.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:50:25 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 14:03:53 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	union		u_arg
{
	void			*vp;
	long			li;
	unsigned long	lu;
	char			c;
}					t_arg;

typedef	struct		s_data
{
	unsigned char	flag_zero : 1;
	unsigned char	flag_minus : 1;
	int				width;
	int				precision;
	char			type;
	const char		*format;
	va_list			var;
	int				i;
	int				char_count;
	t_arg			arg;
	int				fd;
}					t_data;

typedef	struct		s_function
{
	char			type;
	void			(*print)(t_data *data);
}					t_function;

int					ft_dprintf(int fd, const char *format, ...);
void				select_printer(t_data *data);
void				pop_width(t_data *data);
void				pop_precision(t_data *data);
void				pop_flag(t_data *data);
void				populate_execute_struct(t_data *data);
void				reset_struct(t_data *data);
int					intlen(int nb);
int					lulen(long unsigned nb);
void				print(void *ptr, t_data *data);
void				print_per(t_data *data);
void				print_di(t_data *data);
void				print_u(t_data *data);
char				*make_hex(t_data *data, char *str);
void				print_hex(t_data *data);
void				print_s(t_data *data);
void				print_c(t_data *data);
void				print_p(t_data *data);
void				print_char(t_data *data);
void				printf_width_pointer(t_data *data);
void				putstr_printf(char *s, size_t len, t_data *data);
void				putchar_printf(char c, t_data *data);
void				putnbr_printf(int n, t_data *data);
char				is_numeric_type(char c);
void				print_struct(t_data *data);
void				calc_field_width(t_data *data);
char				*ft_itoa_base(unsigned long value, int base, char c);
char				*ft_itoa_base_pointer(unsigned long value, int base);
void				ft_tolower_string(char **string);
void				print_width_ascii(t_data *data);
void				print_di_reg(t_data *data);
void				print_di_neg(t_data *data);
void				print_di_neg_prec(t_data *data);
void				print_di_min(t_data *data);
void				print_di_min_neg(t_data *data);
void				print_di_neg_zero(t_data *data);
void				print_di_neg_zero_prec(t_data *data);
void				putnbr_unsigned_printf(unsigned int n, t_data *data);
void				print_di_min_neg(t_data *data);
void				print_di_min(t_data *data);
void				print_di_null(t_data *data);
void				print_di_null_minus(t_data *data);
void				print_di_zero(t_data *data);
void				print_lu(t_data *data);
void				print_lu_min(t_data *data);
void				print_hexadecimal(t_data *data);
void				print_hexadecimal_min(t_data *data);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*null_pointer(t_data *data);

#endif
