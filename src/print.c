/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 18:15:20 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/08 18:17:07 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		num_tab_needed(t_window *size, t_clist **list)
{
	int	i;

	size->listcount = ft_clistcount(list);
	i = 1;
	while (size->li < size->listcount / i)
		i++;
	return (i);
}

void	ft_fill_struct_window(t_window *size, t_clist **list)
{
	size->tab_counter = 1;
	size->arg_printed = 0;
	size->num_tab = num_tab_needed(size, list);
	size->max_len = ft_maxlen(list);
	size->items_per_tab = size->listcount / size->num_tab + 1;
}

void	ft_print_item(t_clist *item)
{
	if (item->is_cursor)
		tputs(tgetstr("us", NULL), TPUTS_END);
	if (item->is_selected)
		tputs(tgetstr("mr", NULL), TPUTS_END);
	ft_putstr(item->str);
	tputs(tgetstr("me", NULL), TPUTS_END);
}

void	ft_print(t_window *size, t_clist **list)
{
	t_clist	*lst;

	ft_fill_struct_window(size, list);
	ft_putheader(size);
	lst = *list;
	while (lst->next != NULL)
	{
		ft_print_item(lst);
		size->arg_printed++;
		if (size->arg_printed >= size->items_per_tab)
		{
			size->tab_counter++;
			size->arg_printed = 0;
		}
		tputs(tgoto(CM, POSX, POSY),TPUTS_END);
		lst = lst->next;
	}
	ft_print_item(lst);
}
