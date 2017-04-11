/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:11:48 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 16:44:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_print_list_1(t_file_list *begin_list)
{
	t_file_list	*current;

	current = begin_list;
	while (current)
	{
		ft_printf("%s\n", current->str);
		current = current->next;
	}
	ft_remove_list(&begin_list);
}
