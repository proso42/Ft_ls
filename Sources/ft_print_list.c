/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 11:42:34 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 16:39:16 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int		get_size_max(t_file_list *begin_list)
{
	int			size_max;
	t_file_list	*current;

	current = begin_list;
	size_max = 0;
	while (current)
	{
		if ((int)ft_strlen(current->str) > size_max)
			size_max = ft_strlen(current->str);
		current = current->next;
	}
	return (size_max);
}

void	ft_print_list(t_file_list *begin_list)
{
	int			size_max;
	t_file_list	*prev;
	t_file_list	*current;

	size_max = get_size_max(begin_list) + 1;
	current = begin_list;
	prev = current;
	while (current)
	{
		if (!current->next)
			ft_printf("%s\n", current->str);
		else if (current->size <= prev->size)
			ft_printf("%-*s", size_max, current->str);
		else
			ft_printf("\n%-*s", size_max, current->str);
		prev = current;
		current = current->next;
	}
	ft_remove_list(&begin_list);
}
