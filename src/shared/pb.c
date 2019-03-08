/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:49:51 by mmousson          #+#    #+#             */
/*   Updated: 2018/12/20 06:42:14 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_is_a_empty(t_list **stack_a)
{
	t_list *check;

	check = *stack_a;
	if (check == NULL)
		return (1);
	else
		return (0);
}

void				ft_push_b(t_list **stack_a, t_list **stack_b, int write)
{
	t_list *top_a;

	if (write)
		ft_putstr_fd("pb\n", 1);
	if (ft_is_a_empty(stack_a))
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
}
