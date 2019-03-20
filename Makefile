# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 03:28:51 by mmousson          #+#    #+#              #
#    Updated: 2019/03/20 19:08:40 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
LIBFT = libft
LIBS = -lft
LIBSFOLDERS = -L./$(LIBFT)
vpath %.c %(dir MAKEFILE_LIST)
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes -I./libft/includes
CPPFLAGS += -MMD -MP

NAME_PS = push_swap
NAME_CHECK = checker

OBJDIR = .o

SRCS_SHARED =		./src/shared/pa.c					\
					./src/shared/pb.c					\
					./src/shared/ra.c					\
					./src/shared/rb.c					\
					./src/shared/rr.c					\
					./src/shared/rra.c					\
					./src/shared/rrb.c					\
					./src/shared/rrr.c					\
					./src/shared/sa.c					\
					./src/shared/sb.c					\
					./src/shared/ss.c					\
					./src/shared/get_int_list.c			\
					./src/shared/free_list.c			\
					./src/shared/is_sorted.c

SRCS_PUSHSWAP =		./src/push_swap/main.c				\
					./src/push_swap/fill_stack_b.c		\
					./src/push_swap/refill_stack_a.c	\
					./src/push_swap/solve_3.c

SRCS_CHECKER = 		./src/checker/main.c				\
					./src/checker/check_solve.c

OBJS_PUSHSWAP = $(subst .c,.o,$(subst ./src/,./$(OBJDIR)/,$(SRCS_PUSHSWAP)))
OBJS_CHECKER = $(subst .c,.o,$(subst ./src/,./$(OBJDIR)/,$(SRCS_CHECKER)))
OBJS_SHARED = $(subst .c,.o,$(subst ./src/,./$(OBJDIR)/,$(SRCS_SHARED)))

DEPS_PUSHSWAP = $(subst .c,.d,$(subst ./src/,./$(OBJDIR)/,$(SRCS_PUSHSWAP)))
DEPS_CHECKER = $(subst .c,.d,$(subst ./src/,./$(OBJDIR)/,$(SRCS_CHECKER)))
DEPS_SHARED = $(subst .c,.d,$(subst ./src/,./$(OBJDIR)/,$(SRCS_SHARED)))

all: lib_rule $(NAME_CHECK) $(NAME_PS)

$(NAME_CHECK): $(OBJS_CHECKER) $(OBJS_SHARED)
	@$(CC) $(OBJS_CHECKER) $(OBJS_SHARED) -o $(NAME_CHECK) $(LIBSFOLDERS) $(LIBS)
	@printf "\033[1;36m[CHECKER COMPILATION SUCCESSFUL]\033[0m\n"

$(NAME_PS): $(OBJS_PUSHSWAP) $(OBJS_SHARED)
	@$(CC) $(OBJS_PUSHSWAP) $(OBJS_SHARED) -o $(NAME_PS) $(LIBSFOLDERS) $(LIBS)
	@printf "\033[1;36m[PUSH_SWAP COMPILATION SUCCESSFUL]\033[0m\n"

$(OBJDIR):
	@$(shell mkdir -p $(OBJDIR))

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@$(shell mkdir -p $(dir $@))
	@printf "Precompiling $(notdir $@)...\n"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C $(LIBFT) clean --no-print-directory
	@$(RM) $(OBJS_CHECKER) $(OBJS_PUSHSWAP) $(OBJS_SHARED) $(DEPS_CHECKER) $(DEPS_PUSHSWAP) $(DEPS_SHARED)
	@printf "\033[1;33m[PUSH_SWAP AND CHECKER OBJECT FILES CLEANED]\033[0m\n"

fclean:
	@$(MAKE) -C $(LIBFT) fclean --no-print-directory
	@$(RM) $(OBJS_CHECKER) $(OBJS_PUSHSWAP) $(OBJS_SHARED) $(DEPS_CHECKER) $(DEPS_PUSHSWAP) $(DEPS_SHARED)
	@printf "\033[1;33m[PUSH_SWAP AND CHECKER OBJECT FILES CLEANED]\033[0m\n"
	@$(RM) $(NAME_CHECK) $(NAME_PS)
	@printf "\033[1;35m[PUSH_SWAP AND CHECKER BINARIES DELETED]\033[0m\n"

re: fclean all

lib_rule:
	@$(MAKE) -C $(LIBFT) --no-print-directory

.NOTPARALLEL:
.PHONY: lib_rule all clean fclean re re_nolib fclean_nolib
-include $(DEPS_CHECKER) $(DEPS_PUSHSWAP) $(DEPS_SHARED)