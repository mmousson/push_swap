/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:22:34 by mmousson          #+#    #+#             */
/*   Updated: 2018/12/20 06:33:45 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

void	ft_print_list(t_list *integers, char l)
{
	while (integers)
	{
		ft_printf("%c = %ld\n", l, *((int *)(integers->content)));
		integers = integers->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ft_get_int_list(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL)
		ft_putendl("Error");
	else
		ft_putendl("OK");
	return (0);
}
