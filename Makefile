# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonweizmann <antonweizmann@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:57:44 by aweizman          #+#    #+#              #
#    Updated: 2023/12/15 04:35:25 by antonweizma      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= ./includes/printf

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

HEADERS = -I./includes/push_swap.h -I$(LIBFT)/include/ft_printf.h

SRCS	= main init_stack swap rotate utils push reverse_rotate small_sort big_sort fetch_node_a \
		finish

SRC_DIR	= srcs/

OBJ_DIR		= obj/
SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))
OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
OBJ_CHECK		=	.cache_exists
all : $(NAME)

$(NAME): $(SRC) $(LIBFT)/libftprintf.a $(OBJ)
	@echo "compiling push_swap.."
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIBFT)/libftprintf.a $(HEADERS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_CHECK)
		@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT)/libftprintf.a:
	@make -C $(LIBFT)

$(OBJ_CHECK):
		@mkdir -p $(OBJ_DIR)
clean:
	@echo "cleaning up..."
	@rm -fr $(OBJ_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "full cleaning up..."
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

