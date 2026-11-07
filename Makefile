# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchian <tchian@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/01 19:45:03 by tchian            #+#    #+#              #
#    Updated: 2026/11/07 21:13:29 by tchian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	push_swap.c \
		stack_utils.c \		to confirm name
		operations.c \
		algorithm_utils.c

OBJS = $(SRCS:.c=.o)

# The first target is executed by default when running 'make'
all: $(NAME)

# Rule to link the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Pattern rule to compile source files into object files
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

# Action target to clean up intermediate object files
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Declare phony targets so they never conflict with actual files
.PHONY: all clean fclean re


//not ar rcs bec not archiver. used to pack files into static libray achrive
# 1. The Strict 42 Rule Evaluator (CFLAGS)
# The 42 School subject explicitly states that your code must compile with -Wall -Wextra -Werror.
# • Without CFLAGS: If you forget to type these flags even once, your program might compile fine on your computer, but the automated school tester will reject your project instantly and give you a score of 0.
# • Why use the variable: By grouping them inside CFLAGS, we guarantee that every single file gets compiled under these exact, strict rules automatically.
# 2. The "No Relinking" Rule Trap (OBJS)
# This is the most common reason students fail their defense. The 42 subject rules strictly say: "Your Makefile must not perform unnecessary relinking."
# • What is Relinking? If you change just one line of code inside operations.c, a simple Makefile would get lazy and re-compile every single file from scratch (push_swap.c, stack_utils.c, etc.).
# • How OBJS fixes this: By using object files (.o), make becomes incredibly smart. It looks at the timestamps of your files. If you only edited operations.c, it will only re-compile operations.o, and then quickly stitch the program back together.
