# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kris <kris@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/19 23:35:41 by kris          #+#    #+#                  #
#    Updated: 2020/10/15 14:25:43 by kstallen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

HDR = $(IDIR)/cub3d.h

SRC = $(addprefix $(SDIR)/, $(SRC_FILES))
OBJ = $(addprefix $(ODIR)/, $(SRC:$(SDIR)/%.c=%.o))
ODIR = objects
SDIR = sources
IDIR = includes
LDIR = libraries
SRC_FILES = cub3d.c error.c free.c init.c parse.c populate.c utils_elem.c \
test.c validate.c game.c

vpath %.c src

all: $(NAME) libs mlx
	@echo "cub3D is created"
	@echo "usage: ./$(NAME) <file name>"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $? -L$(LDIR)/libft -lft 
	@echo "directory '/$(ODIR)' created"
	@echo "object files compiled and placed in '/$(ODIR)'"
	@echo "object files and libraries are linked"

$(ODIR)/%.o: $(SDIR)/%.c $(HDR) libs
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(IDIR) -I$(LDIR)/libft

libs:
	@make -C $(LDIR)/libft

mlx:
	@make -C ./mlx

clean:
	@$(RM) -r $(ODIR)
	@make clean -C $(LDIR)/libft

fclean: clean
	@$(RM) $(NAME) 
	@make fclean -C $(LDIR)/libft
	@echo "'$(NAME)' cleaned up"

test: re
	@./$(NAME) maps/subject-example.cub

re: fclean all

.PHONY: clean fclean