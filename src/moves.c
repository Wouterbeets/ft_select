/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:22:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 17:28:13 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_move_up(t_clist **list)
{
	(void)list;
	ft_putstr("up");
	return (1);
}

int		ft_move_down(t_clist **list)
{
	(void)list;
	ft_putstr("down");
	return (1);
}

int		ft_move_left(t_clist **list)
{
	(void)list;
	ft_putstr("left");
	return (1);
}

int		ft_move_right(t_clist **list)
{
	(void)list;
	ft_putstr("right");
	return (1);
}
