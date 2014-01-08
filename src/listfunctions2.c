/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunctions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 14:21:47 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/08 18:59:46 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_clist	*ft_del_lst_item(t_clist **old, t_clist *item)
{
	t_clist	*tmpprev;
	t_clist	*tmpnext;

	if ((!(item->next)||!(item->prev)))
	{
		tmpnext = ft_del_start_end(old, item);
		return (tmpnext);
	}
	tmpnext = item->next;
	tmpprev = item->prev;
	tmpprev->next = tmpnext;
	tmpnext->prev = tmpprev;
	free(item->str);
	free(item);
	item = NULL;
	return (tmpnext);
}

t_clist	*ft_del_start_end(t_clist **old, t_clist *item)
{
	t_clist	*tmp;

	if (item->next == NULL && item->prev == NULL)
	{
		tmp = ft_clstnew("");
		return (tmp);
	}
	if (item->next)
	{
		tmp = item->next;
		tmp->prev = NULL;
		*old = tmp;
		return (tmp);
	}
	else
	{
		tmp = item->prev;
		tmp->next =  NULL;
		return (list_start(tmp));
	}
}

t_clist	*list_end(t_clist *item)
{
	ft_putstr("1");
	while (item->next)
	{
		ft_putstr("2");
		item = item->next;
	}
	return (item);
}

t_clist	*list_start(t_clist *item)
{
	ft_putstr("3");
	while (item->prev)
	{
		ft_putstr("4");
		item = item->prev;
	}
	return (item);
}

