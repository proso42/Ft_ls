/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:07:49 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 15:45:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	sort_by_ascii(t_file_list **begin_list)
{
	char		*swap;
	t_file_list	*current;

	current = *begin_list;
	if (current)
	{
		while (current->next)
		{
			if (ft_strcmp(current->str, current->next->str) > 0)
			{
				swap = current->str;
				current->str = current->next->str;
				current->next->str = swap;
				current = *begin_list;
			}
			else
				current = current->next;
		}
		re_init_size(*begin_list);
	}
}
