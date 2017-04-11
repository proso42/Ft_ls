/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:29:05 by proso             #+#    #+#             */
/*   Updated: 2017/04/07 11:28:27 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_file_list		*get_p_elem(t_file_list *begin_list, int i)
{
	t_file_list	*current;

	current = begin_list;
	while (i > 0)
	{
		i--;
		current = current->next;
	}
	return (current);
}
