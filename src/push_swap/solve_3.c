/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 04:23:08 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/14 01:30:22 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

void			print_list(t_list *stack)
{
	while (stack)
	{
		printf("%ld\n", *((long int *)(stack->content)));
		stack = stack->next;
	}
}

static void		delete_last(char *buffer)
{
	char	*pos;

	if ((pos = ft_strrchr(buffer, '\n')) != NULL)
		ft_bzero(pos - 3, 4);
}

// static long		get_hash(t_list *stack)
// {
// 	long	res;

// 	res = 7;
// 	while (stack)
// 	{
// 		res = res * 10 + *((long int *)(stack->content));
// 		stack = stack->next;
// 	}
// 	return (res);
// }

// static long		update_hash(t_holder *holder)
// {
// 	long 			tmp;
// 	t_list			*bkp_a;
// 	t_list			*bkp_b;

// 	bkp_a = *(holder->a_head);
// 	bkp_b = *(holder->b_head);
// 	tmp = get_hash(*(holder->a_head));
// 	tmp += get_hash(*(holder->b_head));
// 	*(holder->a_head) = bkp_a;
// 	*(holder->b_head) = bkp_b;
// 	return (tmp);
// }
int				brute_force(t_holder *holder, int moves, char *result, char *tmp)
{
	int		i;

	if ((ft_is_sorted(*(holder->a_head)) && ft_lstdepth(*(holder->b_head)) == 0))
	{
		ft_strcpy(result, tmp);
		return (1);
	}
	if (moves > holder->lmt
		|| (*result != '\0' && ft_strlen(tmp) > ft_strlen(result)))
		return (0);
	i = -1;
	while (++i < 4)
	{
		holder->dispatcher[i].func(holder->a_head, holder->b_head, 0);
		ft_strcat(tmp, holder->dispatcher[i].move);
		if (brute_force(holder, moves + 1, result, tmp))
			return (1);
		holder->dispatcher[i].reverse(holder->a_head, holder->b_head, 0);
		delete_last(tmp);
	}
	return (0);
}

void			solve_brute_force(t_list **stack_a_head, t_list **stack_b_head)
{
	char					moves[128];
	char					tmp[128];
	t_holder				holder;
	static const t_matcher	dispatcher[5] = {
		{"sa \n", ft_swap_a, ft_swap_a},
		{"ss \n", ft_swap_s, ft_swap_s},
		{"ra \n", ft_rotate_a, ft_reverse_rotate_a},
		{"rra\n", ft_reverse_rotate_a, ft_rotate_a},
		{NULL, NULL, NULL}
	};

	holder.lmt = 0;
	holder.a_head = stack_a_head;
	holder.b_head = stack_b_head;
	holder.dispatcher = dispatcher;
	while (++(holder.lmt) < 13)
	{
		ft_bzero(moves, 128);
		ft_bzero(tmp, 128);
		if (brute_force(&holder, 0, moves, tmp))
		{
			ft_putendl(moves);
			return ;
		}
	}
}
