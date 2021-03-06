# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kstallen <kstallen@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/15 14:21:18 by kstallen      #+#    #+#                  #
#    Updated: 2020/10/28 13:13:25 by kris          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)

NAME=libmlx.dylib

INC=-I.

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@echo "dynamic archive '$(NAME)' made"

%.o: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@

%.swiftmodule: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	@rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~
	@echo "'$(NAME)' object files cleaned up"
