/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:13:32 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/16 02:35:53 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static long int	ft_get_top(t_list **head)
{
	t_list	*cur;

	cur = *head;
	return (*((long int *)(cur->content)));
}

static long int	ft_stack_max(t_list *stack_x)
{
	long int	res;
	long int	tmp;

	res = __LONG_MAX__ * (-1);
	while (stack_x)
	{
		if ((tmp = (*(long int *)(stack_x->content))) > res)
			res = tmp;
		stack_x = stack_x->next;
	}
	return (res);
}

/*
**	This function moves the stack so it will be ready fot the next push
**	Its return value tells us if we must rotate the stack_b afterwrds
*/

static void		ft_move_stack(t_list *stack_b, t_list **stack_b_head, long max)
{
	int			index;
	int			depth;

	index = 0;
	depth = ft_lstdepth(stack_b);
	while (stack_b)
	{
		if ((*(long int *)(stack_b->content)) == max)
			break ;
		index++;
		stack_b = stack_b->next;
	}
	if (index >= depth / 2)
		while (ft_get_top(stack_b_head) != max)
			ft_reverse_rotate_b(NULL, stack_b_head, 1);
	else
		while (ft_get_top(stack_b_head) != max)
			ft_rotate_b(NULL, stack_b_head, 1);
}

void			refill_stack_a(t_list **stack_a_head, t_list **stack_b_head)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *stack_a_head;
	stack_b = *stack_b_head;
	while (stack_b != NULL)
	{
		ft_move_stack(stack_b, &stack_b, ft_stack_max(stack_b));
		ft_push_a(&stack_a, &stack_b, 1);
	}
	*stack_a_head = stack_a;
	*stack_b_head = stack_b;
}
