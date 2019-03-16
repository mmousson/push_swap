/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:25:18 by mmousson          #+#    #+#             */
/*   Updated: 2019/03/16 03:13:22 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_free_samere(t_list *integers, long int *current)
{
	t_list	*tmp;

	ft_memdel((void **)&(current));
	while (integers)
	{
		tmp = integers->next;
		ft_memdel(&(integers->content));
		ft_memdel((void **)&(integers));
		integers = tmp;
	}
	return (NULL);
}
