/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:10:01 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 17:06:28 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	get_x_perm(struct stat buf, int type)
{
	if (type == 1)
	{
		if ((buf.st_mode & S_ISUID) && !(buf.st_mode & S_IXUSR))
			return ('S');
		else if ((buf.st_mode & S_ISUID) && (buf.st_mode & S_IXUSR))
			return ('s');
	}
	else if (type == 2)
	{
		if ((buf.st_mode & S_ISUID) && !(buf.st_mode & S_IXGRP))
			return ('S');
		else if ((buf.st_mode & S_ISUID) && (buf.st_mode & S_IXGRP))
			return ('s');
	}
	else
	{
		if (buf.st_mode & S_ISVTX && !(buf.st_mode & S_IXOTH))
			return ('T');
		else if (buf.st_mode & S_ISVTX && (buf.st_mode & S_IXOTH))
			return ('t');
	}
	if (buf.st_mode & S_IXGRP || buf.st_mode & S_IXUSR || buf.st_mode & S_IXOTH)
		return ('x');
	return ('-');
}

char	get_type_of_file(struct stat buf)
{
	if ((buf.st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((buf.st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((buf.st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((buf.st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	return ('s');
}

char	*get_perm(struct stat buf, char *str, char *path)
{
	char		*perm;

	perm = ft_strnew(11);
	perm[0] = get_type_of_file(buf);
	perm[1] = (buf.st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (buf.st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = get_x_perm(buf, 1);
	perm[4] = (buf.st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (buf.st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = get_x_perm(buf, 2);
	perm[7] = (buf.st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (buf.st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = get_x_perm(buf, 3);
	perm[10] = get_acl(str, path);
	return (perm);
}
