# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kris <kris@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/19 23:35:41 by kris          #+#    #+#                  #
#    Updated: 2020/11/11 15:53:03 by kris          ########   odam.nl          #
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
MLX_COMPILE = -lmlx -Lmlx -Imlx -framework OpenGL -framework AppKit

vpath %.c src

all: $(NAME)
	@echo "cub3D is created"
	@echo "usage: ./$(NAME) <file name>"

$(NAME): $(OBJ) mlx_rule libs
	@$(CC) $(CFLAGS) -o $(NAME) ${OBJ} -L$(LDIR)/libft -lft $(MLX_COMPILE)
	@echo "directory '/$(ODIR)' created"
	@echo "object files compiled and placed in '/$(ODIR)'"
	@echo "object files and libraries are linked"

$(ODIR)/%.o: $(SDIR)/%.c $(HDR) libs mlx_rule
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(IDIR) -I$(LDIR)/libft -I mlx

libs:
	@make -C $(LDIR)/libft

mlx_rule:
	@make -C mlx
	@cp mlx/mlx.h $(IDIR)
	@cp mlx/libmlx.dylib .

clean:
	@$(RM) -r $(ODIR)
	@make clean -C $(LDIR)/libft
	@make clean -C mlx
	@rm libmlx.dylib

fclean: clean
	@$(RM) $(NAME) 
	@make fclean -C $(LDIR)/libft
	@echo "'$(NAME)' cleaned up"
	@rm $(IDIR)/mlx.h

test: re
	@./$(NAME) maps/subject-example.cub

re: fclean all

.PHONY: clean fclean












# SDIR = sources
# SRC			= cub3d.c error.c free.c init.c parse.c populate.c utils_elem.c \
# test.c validate.c game.c
# SRCS = $(addprefix $(SDIR)/, $(SRC))
# OBJS			= $(SRCS:.c=.o)

# CC				= gcc
# RM				= rm -f
# CFLAGS			= -O3 -Wall -Wextra -Iincludes -lft
# LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
# MLX				= libmlx.dylib

# NAME			= cub3D

# all:			$(NAME)

# $(NAME):		$(MLX) $(OBJS) libft
# 				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} -L libraries/libft 

# $(MLX):
# 				@$(MAKE) -C mlx
# 				@cp mlx/$(MLX) .

# libft: 
# 	make -C libraries/libft

# clean:
# 				@$(MAKE) -C mlx clean
# 				$(RM) $(OBJS) $(BONUS_OBJS)

# fclean:			clean
# 				$(RM) $(NAME) $(MLX)

# re:				fclean $(NAME)

# .PHONY:			all clean fclean re