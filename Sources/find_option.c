/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:35:44 by proso             #+#    #+#             */
/*   Updated: 2017/04/05 18:29:36 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	init_option(t_option *option)
{
	option->l = 0;
	option->r = 0;
	option->rr = 0;
	option->a = 0;
	option->t = 0;
	option->one = 0;
	option->m = 0;
	option->s = 0;
	option->f = 0;
}

void	make_str_option(t_option *option)
{
	int		i;

	i = 1;
	option->str_option = ft_strnew(7);
	option->str_option[0] = '-';
	if (option->l)
		option->str_option[i++] = 'l';
	if (option->r)
		option->str_option[i++] = 'r';
	if (option->rr)
		option->str_option[i++] = 'R';
	if (option->a)
		option->str_option[i++] = 'a';
	if (option->t)
		option->str_option[i++] = 't';
	if (option->one)
		option->str_option[i++] = '1';
	if (option->m)
		option->str_option[i++] = 'm';
	if (option->s)
		option->str_option[i++] = 'S';
	if (option->f)
		option->str_option[i++] = 'f';
	if (i == 1)
		ft_strdel(&option->str_option);
}

int		suite(t_option *option, char c)
{
	if (c == 'm')
	{
		option->m = 1;
		option->l = 0;
		option->one = 0;
	}
	else if (c == 'S' && !option->f)
	{
		option->s = 1;
		option->t = 0;
	}
	else if (c == 'f')
	{
		option->f = 1;
		option->a = 1;
		option->s = 0;
		option->t = 0;
	}
	else if (c != 't' && c != 'S')
		return (c);
	return (0);
}

int		check_invalid_option(t_option *option, char c)
{
	if (c == 'r' && !option->f)
		option->r = 1;
	else if (c == 'R')
		option->rr = 1;
	else if (c == 'a')
		option->a = 1;
	else if (c == 't' && !option->s && !option->f)
		option->t = 1;
	else if (c == 'l')
	{
		option->l = 1;
		option->one = 0;
		option->m = 0;
	}
	else if (c == '1')
	{
		option->one = 1;
		option->l = 0;
		option->m = 0;
	}
	else
		return (suite(option, c));
	return (0);
}

int		find_option(t_option *option, char **argv)
{
	int		i;
	char	invalid;

	init_option(option);
	if (argv[1] && ft_strlen(argv[1]) > 1)
	{
		if (argv[1][0] == '-')
		{
			i = 1;
			while (argv[1][i])
			{
				if ((invalid = check_invalid_option(option, argv[1][i])))
					return (invalid);
				i++;
			}
		}
	}
	make_str_option(option);
	return (0);
}
