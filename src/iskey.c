/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:26:01 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 11:54:55 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_clist	*what_arrow(int drctn, t_window *size, t_clist **list, t_clist *item)
{
	if (drctn == 1)
		item = ft_move_up(size, list, item);
	if (drctn == 2)
		item = ft_move_down(size, list, item);
	if (drctn == 3)
		item = ft_move_right(size, list, item);
	if (drctn == 4)
		item = ft_move_left(size, list, item);
	return (item);
}

int		is_arrow(char *buf)
{
	if (buf[0] != 27 || buf[1] != 91)
		return (0);
	if (buf[2] == 65)
		return (1);
	if (buf[2] == 66)
		return (2);
	if (buf[2] == 67)
		return (3);
	if (buf[2] == 68)
		return (4);
	else
		return (0);
}

int		is_space(char *buf)
{
	return (buf[0] == 32);
}

int		is_bspace(char *buf)
{
	return (buf[0] == 127);
}

int		is_del(char *buf)
{
	return(buf[0] == 126);
}

int		is_rtn(char *buf)
{
	return (buf[0] == 10);
}

int		is_esc(char *buf)
{
	return (buf[0] == 27 && buf[1] == 0);
}

int		is_cntrl_z(char *buf)
{
	return (buf[0] == 26);
}

int		is_cntrl_c(char *buf)
{
	return (buf[0] == 3);
}

int		is_alt_r(char *buf)
{
	return (buf[0] == -62);
}
