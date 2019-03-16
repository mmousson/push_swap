/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 01:22:34 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/16 02:38:23 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ft_get_int_list(argc, argv);
	stack_b = NULL;
	if (stack_a == NULL)
		ft_putendl_fd("Error", 2);
	else
	{
		if ((ret = check_solve(&stack_a, &stack_b)) == 1)
			ft_putendl("OK");
		else if (ret == 0)
			ft_putendl("KO");
		else if (ret == -1)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
	}
	return (0);
}
