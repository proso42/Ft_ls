/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:36:02 by proso             #+#    #+#             */
/*   Updated: 2017/03/30 22:03:23 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	re_init_size(t_file_list *begin_list)
{
	t_file_list	*current;

	current = begin_list;
	while (current)
	{
		current->size = ft_strlen(current->str);
		current = current->next;
	}
}

void	get_time_file(t_file_list *current, struct stat buf)
{
	while (current)
	{
		if ((ft_strcmp(".", current->str)))
			lstat(current->str, &buf);
		current->size = buf.st_mtimespec.tv_sec;
		current = current->next;
	}
}

void	sort_by_time(t_file_list **begin_list)
{
	char		*swap;
	int			save;
	struct stat buf;
	t_file_list	*current;

	current = *begin_list;
	lstat(current->str, &buf);
	get_time_file(current, buf);
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
