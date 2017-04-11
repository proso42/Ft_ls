/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:08:44 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:13:25 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	fill_list_l(t_file_list *cur, char *path, char *tmp, t_info *info)
{
	while (cur)
	{
		tmp = ft_strjoin(path, cur->str);
		if ((ft_strcmp(".", cur->str)))
			lstat(tmp, &info->buf);
		ft_strdel(&tmp);
		tmp = get_perm(info->buf, cur->str, path);
		ft_push_back(&info->perm_list, tmp);
		ft_strdel(&tmp);
		tmp = ft_itoa((int)info->buf.st_nlink);
		ft_push_back(&info->link_list, tmp);
		ft_strdel(&tmp);
		ft_push_back(&info->loggin_list, info->pw->pw_name);
		ft_push_back(&info->grp_list, info->gr->gr_name);
		tmp = get_weight(info->buf);
		ft_push_back(&info->weight_list, tmp);
		ft_strdel(&tmp);
		tmp = get_date(info->buf);
		ft_push_back(&info->date_list, tmp);
		ft_strdel(&tmp);
		info->total += info->buf.st_blocks;
		cur = cur->next;
		ft_strdel(&tmp);
	}
}
