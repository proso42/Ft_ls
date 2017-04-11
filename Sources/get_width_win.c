/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:08:02 by proso             #+#    #+#             */
/*   Updated: 2017/03/30 21:53:12 by proso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int		get_width_win(void)
{
	struct winsize	*sz;
	int				width_win;

	if (!(sz = malloc(sizeof(struct winsize))))
		return (-1);
	ioctl(0, TIOCGWINSZ, sz);
	width_win = sz->ws_col;
	free(sz);
	return (width_win);
}
