/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_precision_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:44:06 by proso             #+#    #+#             */
/*   Updated: 2017/03/17 18:59:08 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Include/ft_printf.h"

void	add_min_fieled_s(t_flag *flags)
{
	int		n;
	char	*s;

	n = flags->min_fieled - ft_strlen(flags->arg);
	if (n > 0)
	{
		s = ft_strnew(n);
		ft_memset(s, ' ', n);
		if (flags->moins)
			flags->arg = ft_strjoinfree(flags->arg, s, 3);
		else
			flags->arg = ft_strjoinfree(s, flags->arg, 3);
	}
}

void	add_precision_s(t_flag *flags)
{
	int		n;
	int		i;

	if (flags->conversion == 's')
	{
		if ((int)ft_strlen(flags->arg) > flags->precision)
		{
			n = ft_strlen(flags->arg) - flags->precision;
			i = 0;
			while ((flags->arg)[i])
				i++;
			while (n > 0)
			{
				n--;
				i--;
			}
			(flags->arg)[i] = '\0';
		}
	}
}
