/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:05:44 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/13 19:33:41 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_r(t_list **stack_a, t_list **stack_b, int write)
{
	if (write)
		ft_putstr_fd("rrr\n", 1);
	ft_reverse_rotate_a(stack_a, NULL, 0);
	ft_reverse_rotate_b(NULL, stack_b, 0);
}
