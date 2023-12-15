# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 16:57:44 by aweizman          #+#    #+#              #
#    Updated: 2023/12/15 18:28:47 by aweizman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIBFT	= ./includes/printf

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

ADD = -fsanitize=address -g

DEBUGGER = debugger/

HEADERS = -I./includes/push_swap.h -I$(LIBFT)/include/ft_printf.h

SRCS	= main init_stack swap rotate utils push reverse_rotate big_sort fetch_node_a \
		finish

SRC_DIR	= srcs/

OBJ_DIR		= obj/
SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRCS)))
OBJ 	= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS)))
OBJ_CHECK		=	.cache_exists
all : $(NAME)

$(NAME): $(SRC) $(LIBFT)/libftprintf.a $(OBJ)
	@echo "compiling push_swap.."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)/libftprintf.a $(HEADERS)

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

debug: c $(SRC) $(LIBFT)/libftprintf.a
	@$(CC) $(ADD) $(CFLAGS) $(HEADERS) $(SRC) $(LIBFT)/libftprintf.a
	@mv a.out.dSYM $(DEBUGGER)
	@mv a.out $(DEBUGGER)
	@make fclean

fclean: clean
	@echo "full cleaning up..."
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all

c: fclean
	@rm -rf $(DEBUGGER)*
	@rm -rf *.out *.dSYM *.gch
.PHONY: all clean fclean re

