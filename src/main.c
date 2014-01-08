/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/08 18:19:13 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
		if (is_space(read_char))
			item = ft_select(size, list, item);
		if (is_bspace(read_char))
			item = ft_del_item(size, list, item);
	}
	return (1);
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
	ft_print(&size, &list);
	ft_wait_for_input (&size ,&list);
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	return (0);
}
