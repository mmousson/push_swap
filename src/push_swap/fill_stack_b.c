/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:03:15 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:09:51 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int		ft_are_top_two_smallest(t_list *stack_b)
{
	long int	top1;
	long int	top2;
	long int	catch;

	if (stack_b == NULL || stack_b->next == NULL)
		return (0);
	top1 = *((long int *)(stack_b->content));
	top2 = *((long int *)(stack_b->next->content));
	stack_b = stack_b->next->next;
	while (stack_b != NULL)
	{
		catch = *((long int *)(stack_b->content));
		if(catch < top1 || catch < top2)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

static int		ft_next_to_send_is_on_top(t_list *stack_a, long int median)
{
	int	counter;
	int	depth;

	counter = 0;
	depth = ft_lst_depth(stack_a);
	while (stack_a)
	{
		if (*((long int *)(stack_a->content)) <= median)
		{
			if (counter < depth / 2)
				return (1);
			else
				return (0);
		}
		counter++;
		stack_a = stack_a->next;
	}
	return (0);
}

static long int	ft_find_median(t_list *stack_a)
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
	return (count != 0 ? sum / count : 0);
}

void			fill_stack_b(t_list **stack_a_head, t_list **stack_b_head)
{
	t_list		*stack_a;
	t_list		*stack_b;
	long int	median;

	if (stack_a_head == NULL || stack_b_head == NULL)
		return ;
	stack_a = *stack_a_head;
	stack_b = *stack_b_head;
	median = 2147483647;
	while (stack_a != NULL)
	{
		median = ft_find_median(stack_a);
		if (*((long int *)(stack_a->content)) <= median)
			ft_push_b(&stack_a, &stack_b, 1);
		else if (ft_are_top_two_smallest(stack_a))
			ft_swap_a(&stack_a, NULL, 1);
		else
		{
			if (ft_next_to_send_is_on_top(stack_a, median))
				ft_rotate_a(&stack_a, NULL, 1);
			else
				ft_reverse_rotate_a(&stack_a, NULL, 1);
		}
	}
	*stack_a_head = stack_a;
	*stack_b_head = stack_b;
}
