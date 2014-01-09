/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_del_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:23:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 10:15:26 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_clist	*ft_select(t_window *size, t_clist **list, t_clist *item)
{
	if (item->is_selected)
		item->is_selected = 0;
	else
	{
		item->is_selected = 1;
		item->is_cursor = 0;
		if (item->next)
				item = item->next;
		else
			item = list_start(item);
		item->is_cursor = 1;
	}
	ft_get_size(size);
	ft_print(size, list);
	return (item);
}

t_clist	*ft_del_item(t_window *size, t_clist **list, t_clist *item)
{
	item = ft_del_lst_item(list, item);
	item->is_cursor = 1;
	ft_get_size(size);
	ft_print(size, list);
	return (item);
}

int		ft_maxlen(t_clist **list)
{
	int		i;
	int		len;
	t_clist	*ls;

	len = 0;
	i = 0;
	ls = *list;
	while (ls->next != NULL)
	{
		while (ls->str[i] != '\0')
		{
			if (i > len)
				len = i;
			i++;
		}
		ls = ls->next;
		i = 0;
	}
	return (len + 1);
}
