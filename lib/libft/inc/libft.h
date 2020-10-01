/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:30:05 by kstallen      #+#    #+#                 */
/*   Updated: 2020/09/20 20:14:10 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

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

size_t				ft_strlen(const char *str);
int					ft_numlen(int number);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *h, const char *n, size_t l);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int     			ft_strend(char *str, char *end);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
int					ft_fprintf(int fd, const char *format, ...);
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
int					get_next_line(int fd, char **line);
int					buffer_to_line(int eof, char *buffer, char **buffer_list, char **line);
int					read_and_append_buffer(int fd, char **buffer);

#endif
