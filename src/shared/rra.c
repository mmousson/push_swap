/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:59:53 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:07:54 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_rotate_a(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*head;
	t_list	*tail;
	t_list	*prev;

	(void)stack_b;
	if (write)
		ft_putstr_fd("rra\n", 1);
	head = *stack_a;
	tail = *stack_a;
	prev = NULL;
	if (head == NULL || head->next == NULL)
		return ;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	tail->next = head;
	prev->next = NULL;
	*stack_a = tail;
}
