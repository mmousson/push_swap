/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 04:23:08 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 09:33:27 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*brute_force(t_holder *holder, int moves, char *result, char *tmp)
{
	int				i;

	ft_putendl("Recursive brute force");
	ft_putendl(tmp);
	if ((ft_is_sorted(*(holder->a_head))
			&& ft_lst_depth(*(holder->b_head)) == 0) || moves >= 12)
	{
		if (ft_strlen(result) > ft_strlen(tmp) || *result == '\0')
			ft_strcpy(result, tmp);
		return (NULL);
	}
	i = -1;
	while (++i < 8)
	{
		holder->dispatcher[i].func(holder->a_head, holder->b_head, 0);
		ft_strcat(tmp, holder->dispatcher[i].move);
		brute_force(holder, moves + 1, result, tmp);
		holder->dispatcher[i].reverse(holder->a_head, holder->b_head, 0);
		ft_bzero(ft_strrchr(tmp, '\n') - 3, 4);
	}
	return (NULL);
}

void	solve_brute_force(t_list **stack_a_head, t_list **stack_b_head)
{
	char					moves[128];
	char					tmp[128];
	t_holder				holder;
	static const t_matcher	dispatcher[9] = {
		{"sa \n", ft_swap_a, ft_swap_a},
		{"sb \n", ft_swap_b, ft_swap_b},
		{"ss \n", ft_swap_s, ft_swap_s},
		{"pa \n", ft_push_a, ft_push_b},
		{"pb \n", ft_push_b, ft_push_a},
		{"ra \n", ft_rotate_a, ft_reverse_rotate_a},
		{"rb \n", ft_rotate_b, ft_reverse_rotate_b},
		{"rr \n", ft_rotate_r, ft_reverse_rotate_r},
		{NULL, NULL, NULL}
	};

	ft_bzero(moves, 128);
	ft_bzero(tmp, 128);
	holder.a_head = stack_a_head;
	holder.b_head = stack_b_head;
	holder.dispatcher = dispatcher;
	brute_force(&holder, 0, moves, tmp);
}
