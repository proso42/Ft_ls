/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 22:00:13 by proso             #+#    #+#             */
/*   Updated: 2017/03/31 15:50:04 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	ft_remove_struct(t_info **info)
{
	ft_remove_list(&((*info)->perm_list));
	ft_remove_list(&((*info)->link_list));
	ft_remove_list(&((*info)->grp_list));
	ft_remove_list(&((*info)->date_list));
	ft_remove_list(&((*info)->loggin_list));
	ft_remove_list(&((*info)->weight_list));
	free(*info);
}
