/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:42:34 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 19:49:56 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_push_back(t_file_list **begin_list, char *elem)
{
	t_file_list	*current;
	t_file_list	*new;

	new = (t_file_list*)malloc(sizeof(t_file_list));
	if (!(*begin_list))
	{
		new->str = ft_strdup(elem);
		new->size = ft_strlen(elem);
		new->next = NULL;
		*begin_list = new;
	}
	else
	{
		current = *begin_list;
		while (current->next)
			current = current->next;
		current->next = new;
		new->str = ft_strdup(elem);
		new->size = ft_strlen(elem);
		new->next = NULL;
	}
}
