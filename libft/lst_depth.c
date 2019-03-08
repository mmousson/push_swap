/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_depth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 00:29:04 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/08 00:30:00 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_depth(t_list *list)
{
	int	res;

	res = 0;
	while (list)
	{
		res++;
		list = list->next;
	}
	return (res);
}
