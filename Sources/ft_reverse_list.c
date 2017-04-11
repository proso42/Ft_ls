/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:12:52 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:05:04 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_reverse_list(t_file_list **begin_list)
{
	t_file_list	*curent;
	t_file_list	*previous;
	t_file_list	*swap;

	curent = *begin_list;
	previous = 0;
	while (curent)
	{
		swap = curent->next;
		curent->next = previous;
		previous = curent;
		curent = swap;
	}
	*begin_list = previous;
}
