/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:22:40 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:16:58 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

static void			ft_print_list(t_list *integers, char l)
{
	while (integers)
	{
		ft_printf("%c = %ld\n", l, *((int *)(integers->content)));
		integers = integers->next;
	}
}

int					ft_is_sorted(t_list *stack_a)
{
	long int	tmp;

	tmp = -2147483648;
	while (stack_a)
	{
		if (*((long int *)(stack_a->content)) < tmp)
			return (0);
		else
			tmp = *((long int *)(stack_a->content));
		stack_a = stack_a->next;
	}
	return (1);
}

static int		ft_die(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int				main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			depth;

	stack_b = NULL;
	if ((stack_a = ft_get_int_list(argc, argv)) == NULL)
		return (ft_die("Error\n"));
	if (ft_is_sorted(stack_a))
		return (0);
	depth = ft_lst_depth(stack_a);
	if (depth == 2)
		ft_swap_a(&stack_a, NULL, 1);
	else if (depth <= 5)
		solve_brute_force(&stack_a, &stack_b);
	else
	{
		fill_stack_b(&stack_a, &stack_b);
		ft_print_list(stack_b, 'b');
		refill_stack_a(&stack_a, &stack_b);
		ft_print_list(stack_a, 'a');
	}
	return (0);
}
