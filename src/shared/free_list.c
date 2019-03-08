/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmousson <mmousson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 03:25:18 by mmousson          #+#    #+#             */
/*   Updated: 2018/12/20 03:25:39 by mmousson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_free_samere(t_list *integers)
{
	t_list	*tmp;

	while (integers)
	{
		tmp = integers->next;
		ft_memdel(&(integers->content));
		ft_memdel((void **)&(integers));
		integers = tmp;
	}
	return (NULL);
}
