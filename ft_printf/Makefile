# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 17:26:49 by mmousson          #+#    #+#              #
#    Updated: 2018/12/20 01:22:00 by mmousson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_printf.a
LIBFT = ../libft/libft.a
CFLAGS = -Wextra -Wall -Werror -I./includes -I../libft/includes

SRCS_PRINTF =	./src/attributes.c \
				./src/dispatcher.c \
				./src/flags_conversions.c \
				./src/ft_int_aux.c \
				./src/ft_int.c \
				./src/ft_octal.c \
				./src/ft_octal_aux.c \
				./src/ft_printf.c \
				./src/ft_put_pointer.c \
				./src/put_hexa_aux.c \
				./src/put_hexa.c \
				./src/putchar.c \
				./src/putfloat.c \
				./src/putfloat_aux.c \
				./src/putfloat_main.c \
				./src/putstr.c \
				./src/unsigned_int_aux.c \
				./src/unsigned_int.c \
				./src/magnitude.c

OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS_PRINTF)
	ar rc $(NAME) $(OBJS_PRINTF) $(LIBFT)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS_PRINTF)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
