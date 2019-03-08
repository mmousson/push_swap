/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:33:30 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:14:54 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_s(t_list **stack_a, t_list **stack_b, int write)
{
	if (write)
		ft_putstr_fd("s\n", 1);
	ft_swap_a(stack_a, NULL, 0);
	ft_swap_b(stack_b, NULL, 0);
}
