# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 03:28:51 by mmousson          #+#    #+#              #
#    Updated: 2019/03/08 09:23:16 by mmousson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CHECK = checker

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes -I./libft/includes -I./ft_printf/includes

SRCS_PUSHSWAP =		./src/push_swap/main.c				\
					./src/push_swap/fill_stack_b.c		\
					./src/push_swap/refill_stack_a.c	\
					./src/push_swap/solve_3.c			\
					./src/shared/get_int_list.c			\
					./src/shared/free_list.c			\
					./src/shared/pa.c					\
					./src/shared/pb.c					\
					./src/shared/ra.c					\
					./src/shared/rb.c					\
					./src/shared/rr.c					\
					./src/shared/rra.c					\
					./src/shared/rrb.c					\
					./src/shared/rrr.c					\
					./src/shared/sa.c					\
					./src/shared/sb.c					\
					./src/shared/ss.c

SRCS_CHECKER = 		./src/checker/main.c				\
					./src/shared/get_int_list.c			\
					./src/shared/free_list.c			\
					./src/shared/pa.c					\
					./src/shared/pb.c					\
					./src/shared/ra.c					\
					./src/shared/rb.c					\
					./src/shared/rr.c					\
					./src/shared/rra.c					\
					./src/shared/rrb.c					\
					./src/shared/rrr.c					\
					./src/shared/sa.c					\
					./src/shared/sb.c					\
					./src/shared/ss.c

OBJS_PUSHSWAP = $(SRCS_PUSHSWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

all: $(OBJS_PUSHSWAP) $(OBJS_CHECKER)
	$(MAKE) -C libft
	$(MAKE) -C ft_printf
	$(CC) $(OBJS_PUSHSWAP) -I./includes -I./ft_printf/includes -I./libft/includes ft_printf/ft_printf.a libft/libft.a -o $(NAME_PS)
	$(CC) $(OBJS_CHECKER) -I./includes -I./ft_printf/includes -I./libft/includes ft_printf/ft_printf.a libft/libft.a -o $(NAME_CHECK)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	rm -f $(OBJS_PUSHSWAP) $(OBJS_CHECKER)

fclean: clean
	rm -f ./libft/libft.a
	rm -f ./ft_printf/printf.a
	rm -f $(NAME_PS) $(NAME_CHECK)

re: fclean all

.PHONY: all clean fclean re
