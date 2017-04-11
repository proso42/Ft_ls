/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 22:15:15 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:25:00 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_remove_list(t_file_list **begin_list)
{
	t_file_list	*previous;

	while (*begin_list)
	{
		ft_strdel(&(*begin_list)->str);
		previous = *begin_list;
		*begin_list = (*begin_list)->next;
		free(previous);
	}
	*begin_list = NULL;
}
