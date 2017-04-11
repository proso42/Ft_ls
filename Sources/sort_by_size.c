/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 09:59:49 by proso             #+#    #+#             */
/*   Updated: 2017/03/30 21:51:32 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	get_size_file(t_file_list *current, struct stat buf)
{
	while (current)
	{
		if ((ft_strcmp(".", current->str)))
			lstat(current->str, &buf);
		current->size = buf.st_size;
		current = current->next;
	}
}

void	sort_by_size(t_file_list **begin_list)
{
	char		*swap;
	int			save;
	struct stat	buf;
	t_file_list	*current;

	current = *begin_list;
	lstat(current->str, &buf);
	get_size_file(current, buf);
	current = *begin_list;
	while (current->next)
	{
		if (current->size < current->next->size)
		{
			swap = current->str;
			save = current->size;
			current->str = current->next->str;
			current->size = current->next->size;
			current->next->str = swap;
			current->next->size = save;
			current = *begin_list;
		}
		else
			current = current->next;
	}
}
