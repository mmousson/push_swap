/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:32:29 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:14:43 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_b(t_list **stack_b, t_list **stack_a, int write)
{
	t_list	*curr;
	t_list	*tmp;

	(void)stack_a;
	if (write)
		ft_putstr_fd("sb\n", 1);
	curr = stack_b ? *stack_b : NULL;
	if (curr == NULL || curr->next == NULL)
		return ;
	tmp = curr;
	curr = curr->next;
	tmp->next = curr->next;
	curr->next = tmp;
	*stack_b = curr;
}
