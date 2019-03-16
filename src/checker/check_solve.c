/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 06:08:34 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/16 02:44:37 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	apply_movement(t_list **s_a_head, t_list **s_b_head, char *line)
{
	static const t_matcher	dispatcher[12] = {
		{"sa", ft_swap_a, NULL}, {"sb", ft_swap_b, NULL},
		{"ss", ft_swap_s, NULL}, {"pa", ft_push_a, NULL},
		{"pb", ft_push_b, NULL}, {"ra", ft_rotate_a, NULL},
		{"rb", ft_rotate_b, NULL}, {"rr", ft_rotate_r, NULL},
		{"rra", ft_reverse_rotate_a, NULL}, {"rrb", ft_reverse_rotate_b, NULL},
		{"rrr", ft_reverse_rotate_r, NULL}, {NULL, NULL, NULL}
	};
	const t_matcher			*ptr;

	ptr = dispatcher;
	while (ptr->move != NULL)
	{
		if (ft_strequ(line, ptr->move))
		{
			ptr->func(s_a_head, s_b_head, 0);
			return (1);
		}
		ptr++;
	}
	return (0);
}

int			check_solve(t_list **stack_a_head, t_list **stack_b_head)
{
	int		ret;
	char	*line;
	t_list	*stack_a;
	t_list	*stack_b;

	ret = 0;
	stack_a = *stack_a_head;
	stack_b = *stack_b_head;
	while (get_next_line(0, &line) > 0)
	{
		if (apply_movement(&stack_a, &stack_b, line) == 0)
		{
			ret = -1;
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	if (ret == 0 && ft_is_sorted(stack_a) && ft_lstdepth(stack_b) == 0)
		ret = 1;
	ft_lstdel(&stack_a, &ft_bzero);
	ft_lstdel(&stack_b, &ft_bzero);
	return (ret);
}
