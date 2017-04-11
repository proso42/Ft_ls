/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags_to_buff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:24 by proso             #+#    #+#             */
/*   Updated: 2017/03/19 13:25:42 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "Include/ft_printf.h"

void	get_arg(t_flag *flags, t_print *p)
{
	char	c;

	c = flags->conversion;
	if (c == 'd')
		convert_d(flags, p);
	else if (ft_strchr("ouxX", c))
		convert_oux(flags, p);
	else if (c == 'c' || c == 'C')
		convert_c(flags, p);
	else if (c == 's' || c == 'S')
		convert_s(flags, p);
	else if (c == 'f' || c == 'F')
		convert_f(flags, p);
	else if (c == 'b' || c == 'B')
		convert_b(flags, p);
	else if (c == '%')
		convert_percent(flags);
	else if (c == 'k')
	{
		flags->arg = ft_strnew(1);
		flags->arg[0] = flags->error;
	}
}

void	add_attribute(t_flag *flags, t_print *p)
{
	get_arg(flags, p);
	add_prefixe(flags);
	p->buff = ft_strjoinfree(p->buff, flags->arg, 3);
}
