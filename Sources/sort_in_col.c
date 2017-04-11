/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 21:52:46 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 16:36:53 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int		get_nb_elem(t_file_list *begin_list)
{
	t_file_list	*current;
	int			i;

	i = 0;
	current = begin_list;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	sort_in_col(t_file_list **begin_list)
{
	t_stock		stock;
	t_file_list	*new_list;

	new_list = NULL;
	stock.nb_elem = get_nb_elem(*begin_list);
	stock.inc = (stock.nb_elem / (get_width_win() /
	(get_size_max(*begin_list) + 1))) + ((stock.nb_elem % (get_width_win() /
						(get_size_max(*begin_list) + 1)) > 0) ? 1 : 0);
	stock.j = 0;
	stock.i = 0;
	while (stock.j < stock.inc)
	{
		stock.index = stock.j;
		while (stock.index < stock.nb_elem)
		{
			ft_push_back(&new_list, get_elem(*begin_list, stock.index));
			(get_p_elem(new_list, stock.i++))->size = stock.j;
			stock.index += stock.inc;
		}
		stock.j++;
	}
	ft_remove_list(begin_list);
	*begin_list = new_list;
}
