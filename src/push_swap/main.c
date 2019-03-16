/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:22:40 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/16 03:09:10 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	depth = ft_lstdepth(stack_a);
	if (depth <= 5)
		solve_brute_force(&stack_a, &stack_b);
	else
	{
		fill_stack_b(&stack_a, &stack_b);
		refill_stack_a(&stack_a, &stack_b);
	}
	return (0);
}
