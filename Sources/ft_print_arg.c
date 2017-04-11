/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 17:49:38 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:46:16 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_print_dir(t_file_list *cur, int x, struct stat buf, t_option *o)
{
	DIR				*dirp;
	struct dirent	*data;
	int				i;
	char			*join;

	i = 0;
	while (cur)
	{
		if ((lstat(cur->str, &buf)) >= 0 && (buf.st_mode & S_IFMT) == S_IFDIR)
		{
			if (!(dirp = opendir(cur->str)))
				ft_printf("ft_ls: %s: %s\n", cur->str, strerror(errno));
			else
			{
				(i == 0) ? i++ : write(1, "\n", 1);
				(x) ? ft_printf("%s:\n", cur->str) : write(1, "", 0);
				data = readdir(dirp);
				join = ft_strjoin(cur->str, "/");
				ft_ls(data, dirp, o, join);
				ft_strdel(&join);
				closedir(dirp);
			}
		}
		cur = cur->next;
	}
}

void	ft_print_file(t_file_list *file_list, t_option *option, int i)
{
	if (!option->f)
		sort_by_ascii(&file_list);
	if (option->s)
		sort_by_size(&file_list);
	if (option->t)
		sort_by_time(&file_list);
	if (option->r)
		ft_reverse_list(&file_list);
	choice_print("", file_list, option);
	if (i)
		write(1, "\n", 1);
}

void	ft_print_arg(t_file_list *arg_list, t_option *option)
{
	struct stat		buf;
	int				i;
	t_file_list		*current;
	t_file_list		*file_list;

	current = arg_list;
	i = 0;
	file_list = NULL;
	while (current)
	{
		if ((lstat(current->str, &buf)) < 0)
			ft_printf("ft_ls: %s: %s\n", current->str, strerror(errno));
		else if (!((buf.st_mode & S_IFMT) == S_IFDIR))
			ft_push_back(&file_list, current->str);
		else
			i++;
		current = current->next;
	}
	if (file_list)
		ft_print_file(file_list, option, i);
	current = arg_list;
	if (arg_list)
		ft_print_dir(current, (arg_list->next) ? 1 : 0, buf, option);
}
