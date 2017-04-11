/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:31:15 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 16:42:00 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int		check_total(t_info *info)
{
	t_file_list	*current;

	current = info->perm_list;
	while (current)
	{
		if (current->str[0] == 'd')
			return (1);
		current = current->next;
	}
	return (-1);
}

void	check_access_link(char *path, t_file_list *current)
{
	struct stat	check;
	char		*join;

	join = ft_strjoin(path, current->str);
	lstat(join, &check);
	if (!(check.st_mode & S_IRUSR) && ((check.st_mode & S_IFMT) == S_IFLNK))
		ft_printf("\nft_ls: %s: Permission denied\n", join);
	ft_strdel(&join);
}

void	print_link(char *path, t_file_list *current)
{
	char			buf[256];
	char			*join;
	ssize_t			link;
	struct stat		verif;

	join = ft_strjoin(path, current->str);
	lstat(join, &verif);
	if (verif.st_mode & S_IRUSR)
	{
		link = readlink(join, buf, 256);
		ft_strdel(&join);
		ft_printf(" -> %.*s", link, buf);
	}
	ft_strdel(&join);
}

void	ft_print_list_l(t_file_list *begin_list, char *path, int i)
{
	t_info		*info;
	t_file_list	*current;

	current = begin_list;
	info = get_list_info(begin_list, path);
	if ((check_total(info)) >= 0)
		ft_printf("total : %lu\n", info->total);
	while (current)
	{
		check_access_link(path, current);
		ft_printf("%s  %*s %*s  %*s  %*s %s %s",
			get_elem(info->perm_list, i), info->sx_link,
			get_elem(info->link_list, i), info->sx_loggin,
			get_elem(info->loggin_list, i), info->sx_grp,
			get_elem(info->grp_list, i), info->sx_weight,
			get_elem(info->weight_list, i), get_elem(info->date_list, i),
			current->str);
		if ((get_elem(info->perm_list, i)[0]) == 'l')
			print_link(path, current);
		write(1, "\n", 1);
		i++;
		current = current->next;
	}
	ft_remove_struct(&info);
	ft_remove_list(&begin_list);
}
