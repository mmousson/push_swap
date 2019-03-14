/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:57:26 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/13 19:31:37 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rotate_b(t_list **stack_a, t_list **stack_b, int write)
{
	t_list	*head;
	t_list	*tail;

	(void)stack_a;
	if (write)
		ft_putstr_fd("rb\n", 1);
	head = *stack_b;
	tail = head;
	if (head == NULL || head->next == NULL)
		return ;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	*stack_b = tail->next->next;
	tail->next->next = NULL;
}
