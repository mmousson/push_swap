/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:35:54 by mmousson          #+#    #+#             */
/*   Updated: 2018/12/20 06:42:10 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_is_b_empty(t_list **stack_b)
{
	t_list *check;

	check = *stack_b;
	if (check == NULL)
		return (1);
	else
		return (0);
}

void				ft_push_a(t_list **stack_a, t_list **stack_b, int write)
{
	t_list *top_b;

	if (write)
		ft_putstr_fd("pa\n", 1);
	if (ft_is_b_empty(stack_b))
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
}
