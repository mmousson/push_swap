/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:03:15 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/16 02:51:14 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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

static long int	ft_find_threshold(t_list *stack_a)
{
	long int	count;
	long int	sum;

	sum = 0;
	count = 0;
	while (stack_a != NULL)
	{
		count++;
		sum += *((long int *)(stack_a->content));
		stack_a = stack_a->next;
	}
	return (count != 0 ? sum / (count * 4) : 0);
}

/*
**	This function moves the stack so it will be ready fot the next push
**	Its return value tells us if we must rotate the stack_b afterwrds
*/

static void		ft_move_stack(t_list *stack_a, t_list **stack_a_head,
	long threshold, long max)
{
	int			index;
	int			cur;
	int			depth;
	long int	tmp;

	index = 0;
	cur = -1;
	depth = ft_lstdepth(stack_a);
	while (stack_a)
	{
		if ((tmp = (*(long int *)(stack_a->content))) <= threshold
			|| tmp >= max - threshold)
			if ((index < depth / 2 && cur == -1)
				|| (index >= depth / 2 && (depth - index < cur || cur == -1)))
					cur = index;
		index++;
		stack_a = stack_a->next;
	}
	if (cur >= depth / 2)
		while (--cur > depth / 2)
			ft_reverse_rotate_a(stack_a_head, NULL, 1);
	else
		while (--cur >= 0)
			ft_rotate_a(stack_a_head, NULL, 1);
}

void			fill_stack_b(t_list **stack_a_head, t_list **stack_b_head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	long int	threshold;

	if (stack_a_head == NULL || stack_b_head == NULL)
		return ;
	stack_a = *stack_a_head;
	stack_b = *stack_b_head;
	while (stack_a != NULL)
	{
		threshold = ft_find_threshold(stack_a);
		ft_move_stack(stack_a, &stack_a, threshold, ft_stack_max(stack_a));
		ft_push_b(&stack_a, &stack_b, 1);
		if (*((long int *)(stack_b->content)) <= threshold)
			ft_rotate_b(NULL, &stack_b, 1);
	}
	*stack_a_head = stack_a;
	*stack_b_head = stack_b;
}
