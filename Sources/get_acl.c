/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_acl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 20:05:24 by proso             #+#    #+#             */
/*   Updated: 2017/03/30 21:49:06 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

char	get_acl(char *str, char *path)
{
	char		*join;
	ssize_t		xattr;
	acl_t		acl;
	acl_entry_t dummy;

	join = ft_strjoin(path, str);
	acl = acl_get_link_np(join, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
		acl_free(acl);
	xattr = listxattr(join, NULL, 0, XATTR_NOFOLLOW);
	ft_strdel(&join);
	if (xattr > 0)
		return ('@');
	else if (acl != NULL)
	{
		acl_free(acl);
		return ('+');
	}
	else
		return (' ');
}
