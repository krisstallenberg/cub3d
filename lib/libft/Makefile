# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kstallen <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/14 16:47:18 by kstallen      #+#    #+#                  #
#    Updated: 2020/09/20 20:12:58 by kris          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCL = -Iinc
SDIR = src
ODIR = obj
OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))
SRC = ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memcpy.c ft_memset.c ft_strchr.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
ft_strnstr.c ft_tolower.c ft_toupper.c ft_bzero.c \
ft_atoi.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memmove.c ft_strrchr.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strend.c ft_numlen.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c \
ft_fprintf.c populate.c print1.c print2.c print_utils.c utils.c libft.c \
print_di.c print_di_minus.c print_hex.c print_lu.c print_utils.c \
get_next_line.c get_next_line_utils.c 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "static archive '$(NAME)' made"

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< $(INCL) -o $@

clean:
	@$(RM) -rf $(ODIR)
	@echo "'$(NAME)' object files cleaned up"

fclean: clean
	@$(RM) $(NAME)
	@echo "'$(NAME)' static archive cleaned up"

re: fclean all

bonus:
	$(MAKE) WITH_BONUS=1 all

.PHONY: clean fclean re bonus
