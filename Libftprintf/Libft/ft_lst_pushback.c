/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 10:05:59 by proso             #+#    #+#             */
/*   Updated: 2017/01/19 15:05:29 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "libft.h"

t_list	*ft_lst_pushback(t_list **begin_list, t_list *new)
{
	t_list	*current;

	if (!new)
		return (NULL);
	if (!(*begin_list))
	{
		*begin_list = new;
		return (new);
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = new;
	return (new);
}
