/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:15:31 by proso             #+#    #+#             */
/*   Updated: 2017/03/30 21:53:55 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_file_list	*ft_dup_list(t_file_list *begin_list)
{
	t_file_list	*new_list;

	new_list = NULL;
	while (begin_list)
	{
		ft_push_back(&new_list, begin_list->str);
		begin_list = begin_list->next;
	}
	return (new_list);
}
