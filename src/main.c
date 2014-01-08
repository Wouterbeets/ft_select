/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/08 11:05:50 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int		ft_wait_for_input(t_window *size, t_clist **list)
{
	char	read_char[5];
	int		direction;
	t_clist	*item;

	item = *list;
	while (!(is_rtn(read_char)))
	{
		read(0, read_char, 5);
		if ((direction = is_arrow(read_char)))
		{
			if (direction == 1)
				item = ft_move_up(size, list, item);
			if (direction == 2)
				item = ft_move_down(size, list, item);
			if (direction == 3)
				item = ft_move_right(size, list, item);
			if (direction == 4)
				item = ft_move_left(size, list, item);
		}
	}
	return (1);
}

void	ft_printlist(t_clist *list)
{
	t_clist	*tmp;

	tmp = list;
	while (tmp->next != NULL)
	{
		ft_putendl((char *)tmp->str);
		tmp = tmp->next;
	}
	ft_putendl((char *)tmp->str);
}

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
	if (item->is_cursor == 1)
		tputs(tgetstr("us", NULL), TPUTS_END);
	ft_putstr(item->str);
	tputs(tgetstr("ue", NULL), TPUTS_END);
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

int		main(int argc, char **argv)
{
	struct termios	term;
	t_window		size;
	t_clist			*list;

	(void)argv;
	if ((!ft_set_stage(argc, &term))||(!ft_get_size(&size)))
		return (-1);
	list = ft_get_list(argv);
//	ft_set_tabs(&size, &list);
	ft_print(&size, &list);
//	ft_printlist(list);
	ft_wait_for_input (&size ,&list);
	return (0);
}
