# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 03:28:51 by mmousson          #+#    #+#              #
#    Updated: 2019/03/16 04:23:09 by mmousson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CHECK = checker
LOGFOLDER = ~/push_swap_logs

CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror -I./includes -I./libft/includes

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

OBJS_PUSHSWAP = $(SRCS_PUSHSWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
OBJS_SHARED = $(SRCS_SHARED:.c=.o)

.NOTPARALLEL:

all: lib_rule $(NAME_PS) $(NAME_CHECK)
	@if [ ! -e ps_chk_relink ]; then \
		printf "\033[1;31m      [PUSH_SWAP: NOTHING TO BE DONE]\033[0m\n"; \
	fi;
	@rm -f ps_chk_relink
	@rm -f files_missing

lib_rule:
	@$(MAKE) --no-print-directory -C libft

%.o: %.c
	@if [ ! -e ps_chk_link ]; then \
		rm -rf $(LOGFOLDER); \
		/bin/mkdir $(LOGFOLDER); \
		printf "%-40s" "Precompiling $(notdir $<)..."; \
		touch ps_chk_relink; \
	fi;
	@$(CC) -c $< $(CFLAGS) -o $@ 2> $(LOGFOLDER)/tmp.log || /usr/bin/touch $(LOGFOLDER)/tmp.errors
	@if test -e $(LOGFOLDER)/tmp.errors; then /bin/cat $(LOGFOLDER)/tmp.log; elif test -s$(LOGFOLDER)/tmp.log; then /bin/cat $(LOGFOLDER)/tmp.log; fi;
	@if test -e $(LOGFOLDER)/tmp.errors; \
		then echo "\x1b[1;31m[KO]\x1b[0m" && /bin/cat 1>&2 $(LOGFOLDER)/tmp.log && touch files_missing; \
	elif test -s $(LOGFOLDER)/tmp.log; then \
		echo "\x1b[1;33m[WARNING]\x1b[0m" && /bin/cat $(LOGFOLDER)/tmp.log; \
	else \
		echo "\x1b[1;32m[OK]\x1b[0m"; fi;
	@rm -f $(LOGFOLDER)/tmp.log && rm -f $(LOGFOLDER)/tmp.errors

$(NAME_PS): $(OBJS_SHARED) $(OBJS_PUSHSWAP)
	@$(CC) $(OBJS_PUSHSWAP) $(OBJS_SHARED) -I./includes -I./libft/includes libft/libft.a -o $(NAME_PS)
	@printf "\033[1;36m     [PUSH_SWAP COMPILATION SUCCESSFUL]\033[0m\n"

$(NAME_CHECK): $(OBJS_SHARED) $(OBJS_CHECKER)
	@$(CC) $(OBJS_CHECKER) $(OBJS_SHARED) -I./includes -I./libft/includes libft/libft.a -o $(NAME_CHECK)
	@printf "\033[1;36m      [CHECKER COMPILATION SUCCESSFUL]\033[0m\n"

clean:
	@$(MAKE) --no-print-directory -C libft clean
	@rm -f $(OBJS_PUSHSWAP) $(OBJS_CHECKER) $(OBJS_SHARED)
	@printf "\033[1;33m[PUSH_SWAP AND CHECKER OBJECT FILES CLEANED]\033[0m\n"

fclean:
	@$(MAKE) --no-print-directory -C libft fclean
	@rm -f $(OBJS_PUSHSWAP) $(OBJS_CHECKER) $(OBJS_SHARED)
	@printf "\033[1;33m[PUSH_SWAP AND CHECKER OBJECT FILES CLEANED]\033[0m\n"
	@rm -f $(NAME_PS) $(NAME_CHECK)
	@printf "\033[1;35m  [PUSH_SWAP AND CHECKER BINARIES DELETED]\033[0m\n"

fclean_nolib:
	@/bin/rm -f files_missing
	@rm -f $(OBJS_PUSHSWAP) $(OBJS_CHECKER) $(OBJS_SHARED)
	@printf "\033[1;33m[PUSH_SWAP AND CHECKER OBJECT FILES CLEANED]\033[0m\n"
	@rm -f $(NAME_PS) $(NAME_CHECK)
	@printf "\033[1;35m  [PUSH_SWAP AND CHECKER BINARIES DELETED]\033[0m\n"

re: fclean all
re_nolib: fclean_nolib all

.PHONY: all clean fclean re re_nolib fclean_nolib
