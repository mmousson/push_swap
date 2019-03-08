/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:58:08 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:13:59 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_r(t_list **stack_a, t_list **stack_b, int write)
{
	if (write)
		ft_putstr_fd("rr\n", 1);
	ft_rotate_a(stack_a, NULL, 0);
	ft_rotate_b(stack_b, NULL, 0);
}
