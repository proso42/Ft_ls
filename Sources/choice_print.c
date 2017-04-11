/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 21:53:16 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:46:18 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	choice_print(char *path, t_file_list *name_list, t_option *option)
{
	if (!option->l && !option->one && !option->m)
	{
		if (get_width_win() <= (get_size_max(name_list) * 2))
			ft_print_list_1(name_list);
		else
		{
			sort_in_col(&name_list);
			ft_print_list(name_list);
		}
	}
	else if (option->m)
		ft_print_list_m(name_list);
	else if (option->l)
		ft_print_list_l(name_list, path, 0);
	else if (option->one)
		ft_print_list_1(name_list);
}
