/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:07:21 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:16:15 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	*get_weight(struct stat buf)
{
	int		min;
	int		maj;
	char	*wei;

	if ((buf.st_mode & S_IFMT) == S_IFCHR || (buf.st_mode & S_IFMT) == S_IFBLK)
	{
		min = minor(buf.st_rdev);
		maj = major(buf.st_rdev);
		wei = ft_itoa(maj);
		wei = ft_strjoinfree(wei, ", ", 1);
		wei = ft_strjoinfree(wei, ft_itoa(min), 3);
	}
	else
		wei = ft_itoa(buf.st_size);
	return (wei);
}

char	*get_date(struct stat buf)
{
	char	*date;
	char	*year;

	if (time(NULL) - buf.st_mtimespec.tv_sec > 15811200)
	{
		date = ft_strsub((ctime(&buf.st_mtimespec.tv_sec)), 4, 7);
		year = ft_strsub((ctime(&buf.st_mtimespec.tv_sec)), 20, 4);
		year = ft_strjoinfree(" ", year, 2);
		date = ft_strjoinfree(date, year, 3);
	}
	else
		date = ft_strsub((ctime(&buf.st_mtimespec.tv_sec)), 4, 12);
	return (date);
}

void	get_sx_lists(t_info *info)
{
	info->sx_link = get_size_max(info->link_list);
	info->sx_loggin = get_size_max(info->loggin_list);
	info->sx_grp = get_size_max(info->grp_list);
	info->sx_weight = get_size_max(info->weight_list);
}

t_info	*init_lists(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	info->perm_list = NULL;
	info->link_list = NULL;
	info->loggin_list = NULL;
	info->grp_list = NULL;
	info->weight_list = NULL;
	info->date_list = NULL;
	info->total = 0;
	return (info);
}

t_info	*get_list_info(t_file_list *begin_list, char *path)
{
	t_info		*info;
	t_file_list	*current;
	char		*tmp;

	info = init_lists();
	current = begin_list;
	tmp = ft_strjoin(path, current->str);
	lstat(tmp, &info->buf);
	ft_strdel(&tmp);
	info->pw = getpwuid(info->buf.st_uid);
	info->gr = getgrgid(info->buf.st_gid);
	fill_list_l(current, path, tmp, info);
	get_sx_lists(info);
	return (info);
}
