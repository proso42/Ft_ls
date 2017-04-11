/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:10:23 by proso             #+#    #+#             */
/*   Updated: 2017/01/11 11:27:21 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	int		i;
	char	*dst2;
	char	*src2;

	i = 0;
	dst2 = dst;
	src2 = (void *)src;
	while (n > 0)
	{
		dst2[i] = src2[i];
		i++;
		n--;
	}
	return (dst);
}
