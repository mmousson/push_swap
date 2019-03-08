/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:52:06 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:07:06 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate_a(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*head;
	t_list	*tail;

	(void)stack_b;
	if (write)
		ft_putstr_fd("ra\n", 1);
	head = *stack_a;
	tail = head;
	if (head == NULL || head->next == NULL)
		return ;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	*stack_a = tail->next->next;
	tail->next->next = NULL;
}
