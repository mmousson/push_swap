/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:09:55 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/13 23:05:53 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct		s_matcher
{
	char			*move;
	void			(*func) (t_list **stack_a, t_list **stack_b, int write);
	void			(*reverse) (t_list **stack_a, t_list **stack_b, int write);
}					t_matcher;

typedef struct		s_holder
{
	const t_matcher	*dispatcher;
	t_list			**a_head;
	t_list			**b_head;
	int				lmt;
}					t_holder;

int					check_solve(t_list **stack_a_head, t_list **stack_b_head);
int					ft_is_sorted(t_list *stack_a);
int					ft_is_top_biggest(t_list *stack_b);
int					ft_are_top_two_biggest(t_list *stack_b);

void				fill_stack_b(t_list **stack_a_head, t_list **stack_b_head);
void				refill_stack_a(t_list **stack_a_head, t_list **stack_b_head);

void				solve_brute_force(t_list **stack_a_head, t_list **stack_b_head);

void				ft_swap_a(t_list **stack_a, t_list **null, int write);
void				ft_swap_b(t_list **stack_b, t_list **null, int write);
void				ft_swap_s(t_list **stack_a, t_list **stack_b, int write);
void				ft_push_a(t_list **stack_a, t_list **stack_b, int write);
void				ft_push_b(t_list **stack_a, t_list **stack_b, int write);
void				ft_rotate_a(t_list **stack_a, t_list **null, int write);
void				ft_rotate_b(t_list **null, t_list **stack_b, int write);
void				ft_rotate_r(t_list **stack_a, t_list **stack_b, int write);
void				ft_reverse_rotate_a(t_list **stack_a, t_list **null, int write);
void				ft_reverse_rotate_b(t_list **null, t_list **stack_b, int write);
void				ft_reverse_rotate_r(t_list **stack_a, t_list **stack_b, int write);

/*
**	Checker functions
*/

t_list				*ft_get_int_list(int argc, char **argv);

/*
**	Shared functions
*/

t_list				*ft_free_samere(t_list *integers);

#endif
