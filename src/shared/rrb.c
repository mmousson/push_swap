/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:04:52 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/13 19:33:25 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_rotate_b(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*head;
	t_list	*tail;
	t_list	*prev;

	(void)stack_a;
	if (write)
		ft_putstr_fd("rrb\n", 1);
	head = *stack_b;
	tail = *stack_b;
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
	*stack_b = tail;
}
