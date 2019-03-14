/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 06:41:59 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/12 06:42:07 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_is_sorted(t_list *stack_a)
{
	long int	tmp;

	tmp = -2147483648;
	while (stack_a)
	{
		if (*((long int *)(stack_a->content)) < tmp)
			return (0);
		else
			tmp = *((long int *)(stack_a->content));
		stack_a = stack_a->next;
	}
	return (1);
}
