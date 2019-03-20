/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:13:27 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/20 19:17:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int		ft_check_args(int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 0;
	while (++i < argc)
	{
		tmp = argv[i];
		while (*tmp != '\0')
		{
			if (!ft_isdigit(*tmp) && *tmp != ' ')
				return (0);
			tmp++;
		}
	}
	return (1);
}

static int		ft_has_duplicate_entries(t_list *arg_list)
{
	long int	*save;
	int			pos;
	int			i;
	int			depth;

	pos = -1;
	if ((depth = ft_lstdepth(arg_list)) == 0
		|| (save = (long int *)ft_memalloc(sizeof(long int) * depth)) == NULL)
		return (-1);
	while (++pos < depth)
	{
		save[pos] = *(long int *)(arg_list->content);
		i = -1;
		while (++i < pos)
		{
			if (save[i] == save[pos])
			{
				ft_memdel((void **)&(save));
				return (1);
			}
		}
		arg_list = arg_list->next;
	}
	ft_memdel((void **)&(save));
	return (0);
}

t_list			*ft_get_int_list(int argc, char **argv)
{
	int			i;
	t_list		*result;
	long int	*content;

	result = NULL;
	if (!ft_check_args(argc, argv))
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		if ((content = (long int *)ft_memalloc(sizeof(long int))) == NULL)
			return (ft_free_samere(result, NULL));
		*content = ft_atol(argv[i]);
		if (*content > INT_MAX || *content < INT_MIN)
			return (ft_free_samere(result, content));
		ft_lstpush(&result, ft_lstnew(content, sizeof(long int)));
		ft_memdel((void **)&(content));
	}
	if ((i = ft_has_duplicate_entries(result)) == 1)
		return (ft_free_samere(result, NULL));
	return (result);
}
