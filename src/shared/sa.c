/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:32:22 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:08:51 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*curr;
	t_list	*tmp;

	(void)stack_b;
	if (write)
		ft_putstr_fd("sa\n", 1);
	curr = stack_a ? *stack_a : NULL;
	if (curr == NULL || curr->next == NULL)
		return ;
	tmp = curr;
	curr = curr->next;
	tmp->next = curr->next;
	curr->next = tmp;
	*stack_a = curr;
}
