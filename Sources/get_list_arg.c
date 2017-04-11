/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 18:36:26 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 15:44:57 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int			check_file(char *str)
{
	struct stat	buf;

	if ((lstat(str, &buf)) < 0)
	{
		ft_printf("ft_ls: %s: %s\n", str, strerror(errno));
		return (0);
	}
	return (1);
}

t_file_list	*get_list_arg(int ac, char **av, t_option *option)
{
	t_file_list	*arg_list;
	int			i;

	arg_list = NULL;
	if ((!option->str_option && ac == 1) || (option->str_option && ac == 2))
	{
		ft_push_back(&arg_list, ".");
		return (arg_list);
	}
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && i > 1)
		{
			if (check_file(av[i]))
				ft_push_back(&arg_list, av[i]);
		}
		else if (av[i][0] != '-')
			ft_push_back(&arg_list, av[i]);
		i++;
	}
	sort_by_ascii(&arg_list);
	return (arg_list);
}
