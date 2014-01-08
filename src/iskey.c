/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:26:01 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/08 13:22:50 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_rtn(char *buf)
{
	return (buf[0] == 10);
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
	if (buf[0] == 32)
		return (1);
	return (0);
}
