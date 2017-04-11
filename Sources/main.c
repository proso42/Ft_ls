/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:43:22 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:44:29 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_file_list	*get_name_list(struct dirent *data, DIR *dirp, t_option *option)
{
	t_file_list	*name_list;

	name_list = NULL;
	while (data)
	{
		if ((data->d_name[0] == '.' && option->a) || data->d_name[0] != '.')
			ft_push_back(&name_list, data->d_name);
		data = readdir(dirp);
	}
	return (name_list);
}

void		call_ft_ls(DIR *dirp, struct dirent *data, char **join, t_option *o)
{
	data = readdir(dirp);
	*join = ft_strjoinfree(*join, "/", 1);
	ft_ls(data, dirp, o, *join);
	closedir(dirp);
}

void		recursive_print(char *path, t_option *opt, t_file_list *name_list)
{
	DIR				*dirp;
	struct stat		buf;
	struct dirent	*data;
	char			*join;
	t_file_list		*current;

	current = name_list;
	data = NULL;
	while (current)
	{
		join = ft_strjoin(path, current->str);
		lstat(join, &buf);
		if ((buf.st_mode & S_IFMT) == S_IFDIR && (ft_strcmp(current->str, ".")
											&& (ft_strcmp(current->str, ".."))))
		{
			dirp = opendir(join);
			ft_printf("\n%s:\n", join);
			if (!dirp)
				ft_printf("ft_ls: %s: %s\n", current->str, strerror(errno));
			else
				call_ft_ls(dirp, data, &join, opt);
		}
		ft_strdel(&join);
		current = current->next;
	}
}

int			ft_ls(struct dirent *data, DIR *dirp, t_option *option, char *path)
{
	t_file_list	*name_list;
	t_file_list	*save_list;

	name_list = get_name_list(data, dirp, option);
	save_list = ft_dup_list(name_list);
	if (name_list)
	{
		if (!option->f)
			sort_by_ascii(&name_list);
		if (option->s)
			sort_by_size(&name_list);
		if (option->t)
			sort_by_time(&name_list);
		if (option->r)
			ft_reverse_list(&name_list);
		choice_print(path, name_list, option);
	}
	if (option->rr)
		recursive_print(path, option, save_list);
	if (save_list)
		ft_remove_list(&save_list);
	return (0);
}

int			main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*data;
	t_option		option;
	t_file_list		*arg_list;

	if (find_option(&option, argv))
	{
		ft_printf("ft_ls: illegal option -- %c\n");
		ft_printf("usage: ft_ls [-lrRafmtS1] [file ...]\n");
		return (0);
	}
	if ((!option.str_option && argc == 1) || (option.str_option && argc == 2))
	{
		dirp = opendir("./");
		data = readdir(dirp);
		ft_ls(data, dirp, &option, "./");
		return (0);
	}
	arg_list = get_list_arg(argc, argv, &option);
	if (arg_list)
		ft_print_arg(arg_list, &option);
	return (0);
}
