/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:10:53 by proso             #+#    #+#             */
/*   Updated: 2016/11/26 13:16:48 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*prev;
	t_list	*after;

	current = *alst;
	while (current)
	{
		prev = current;
		after = current->next;
		del((*current).content, (*current).content_size);
		current = after;
		free(prev);
	}
	*alst = NULL;
}
