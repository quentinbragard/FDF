# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbragard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/08 15:57:54 by qbragard          #+#    #+#              #
#    Updated: 2019/09/17 10:06:31 by qbragard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, $(NAME)

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

# ****************************       FDF        ****************************** #
# ********************************         *********************************** #

NAME       = fdf
SRCS_PATH  = srcs/
OBJS_PATH  = objs/
SRC_NAME   = main.c parser.c lines.c lines_bis.c bresenham.c \
draw_pixels.c coord_modif.c coord_modif2.c parser2.c parser3.c hook.c \
hook2.c color.c free.c
OBJ_NAME   = $(SRC_NAME:.c=.o)
SRCS       = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS       = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #

CC      = gcc -I includes
CFLAGS  = -Wall -Wextra -Werror
LFLAGS	= -lmlx -framework OpenGL -framework AppKit
LIB_DEP = $(shell find libft/*.c)
LIBFT = libft/libft.a


all : $(NAME) $(NAME2)
$(LIBFT) : FORCE
	@make -C libft

# ****************************        FDF       ****************************** #

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c libft/libft.a includes/fdf.h
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "                                                               \\r"
	@printf "$(NAME) -- $<\\r"

$(NAME) : $(LIBFT) $(OBJS)
	@printf "                                                               \\r"
	@$(CC) $(CFLAGS) $(LFLAGS) $^ -o $(NAME) -L libft -lft
	@printf "\033[32;1m$(NAME)        [ OK! ]\033[0m\\n"

# **************************************************************************** #
#                                  COMMANDS                                    #
# **************************************************************************** #


FORCE :

clean :
	@rm -rf objs
	@make clean -sC libft
	@printf "make: cleaning objs\\n"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -sC libft
	@printf "make: cleaning programs\\n"

re : fclean all
