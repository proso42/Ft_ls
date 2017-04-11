/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:47:12 by proso             #+#    #+#             */
/*   Updated: 2017/03/30 21:51:02 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	*get_elem(t_file_list *begin_list, int i)
{
	t_file_list	*current;

	current = begin_list;
	while (i > 0)
	{
		i--;
		current = current->next;
	}
	return (current->str);
}
