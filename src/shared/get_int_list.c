/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 02:13:27 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/12 06:38:45 by mmousson         ###   ########.fr       */
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
		content = (long int *)ft_memalloc(sizeof(long int));
		*content = ft_atol(argv[i]);
		if (*content > INT_MAX || *content < INT_MIN)
			return (ft_free_samere(result));
		ft_lstpush(&result, ft_lstnew(content, sizeof(long int)));
		ft_memdel((void **)&(content));
	}
	return (result);
}
