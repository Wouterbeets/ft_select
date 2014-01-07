/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 20:05:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int		ft_wait_for_input(t_clist **list)
{
	char	read_char[5];
	int		direction;

	while (!(is_rtn(read_char)))
	{
		read(0, read_char, 5);
		if ((direction = is_arrow(read_char)))
		{
			if (direction == 1)
				ft_move_up(list);
			if (direction == 2)
				ft_move_down(list);
			if (direction == 3)
				ft_move_right(list);
			if (direction == 4)
				ft_move_left(list);
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

void	ft_print(t_window *size, t_clist **list)
{
	t_clist	*lst;

	lst = *list;
	size->arg_printed = 0;
	size->num_tab = num_tab_needed(size, list);
	size->max_len = ft_maxlen(list);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	ft_putheader();
	while (lst->next != NULL)
	{
		ft_putstr(lst->str);
		size->arg_printed++;
		if (size->arg_printed > size->li)
		{
			tputs(tgoto(tgetstr("cm", NULL), size->max_len + 3, 0), 1, tputs_putchar);
			size->num_tab--;
		}
		tputs(tgetstr("do", NULL), 1, tputs_putchar);
		lst = lst->next;
	}
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
	ft_printlist(list);
	ft_wait_for_input(&list);
	return (0);
}


