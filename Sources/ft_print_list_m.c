/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:45:28 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 16:46:10 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_print_list_m(t_file_list *begin_list)
{
	int			win;
	int			line;
	int			size;
	t_file_list	*current;

	line = 0;
	win = get_width_win();
	current = begin_list;
	while (current)
	{
		size = ft_strlen(current->str);
		if (line + size + 1 <= win)
		{
			ft_printf("%s", current->str);
			(current->next) ? write(1, ", ", 2) : write(1, "\n", 1);
			line += size + 2;
			current = current->next;
		}
		else
		{
			write(1, "\n", 1);
			line = 0;
		}
	}
	ft_remove_list(&begin_list);
}
