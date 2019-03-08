# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 00:53:31 by mmousson          #+#    #+#              #
#    Updated: 2018/12/15 03:43:33 by mmousson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes

SRCS_LIBFT =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_strlen.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strrstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_atol.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_putchar.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstpush.c \
			ft_lstmap.c \
			ft_rotate_left.c \
			ft_stradd.c \
			ft_strmultiply.c \
			ft_putllong.c \
			ft_putfloat.c \
			ft_min.c \
			ft_max.c \
			ft_abs.c \
			ft_clamp.c \
			lst_depth.c	\
			ft_strdivide_two.c

OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_LIBFT)
	ar rc $(NAME) $(OBJS_LIBFT)
	ranlib $(NAME)

clean:
	rm -f $(OBJS_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re