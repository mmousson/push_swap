/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 23:13:32 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:11:31 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ft_is_top_biggest(t_list *stack_b)
{
	long int	top;
	long int	catch;

	if (stack_b == NULL)
		return (0);
	top = *((long int *)(stack_b->content));
	while (stack_b != NULL)
	{
		catch = *((long int *)(stack_b->content));
		if (catch > top)
			return (0);
		else
		stack_b = stack_b->next;
	}
	return (1);
}

int		ft_are_top_two_biggest(t_list *stack_b)
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
		if(catch > top1 || catch > top2)
			return (0);
		stack_b = stack_b->next;
	}
	return (1);
}

void	refill_stack_a(t_list **stack_a_head, t_list **stack_b_head)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = *stack_a_head;
	stack_b = *stack_b_head;
	while (stack_b != NULL)
	{
		if (ft_is_top_biggest(stack_b))
			ft_push_a(&stack_a, &stack_b, 1);
		else if (ft_are_top_two_biggest(stack_b))
			ft_swap_b(&stack_b, NULL, 1);
		else
		{
			ft_rotate_b(&stack_b, NULL, 1);
		}
	}
	*stack_a_head = stack_a;
	*stack_b_head = stack_b;
}
