/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 13:13:11 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	ft_refresh(t_window *size, t_clist **list)
{
	ft_get_size(size);
	ft_print(size, list);
}

int		ft_wait_for_input(t_window *size, t_clist **list)
{
	char	read_char[5];
	int		direction;
	t_clist	*item;

	item = *list;
	while (!(is_rtn(read_char)))
	{
		read_char[1] = 0;
		read(0, read_char, 5);
		if ((direction = is_arrow(read_char)))
			item = what_arrow(direction, size, list, item);
		if (is_space(read_char))
			item = ft_select(size, list, item);
		if (is_bspace(read_char)|| is_del(read_char))
			item = ft_del_item(size, list, item);
		if (is_esc(read_char))
			return (0);
		if (is_cntrl_z(read_char))
			item = ft_select(size, list, item);
		if (is_cntrl_c(read_char))
			item = ft_select(size, list, item);
		if (is_alt_r(read_char))
			ft_refresh(size, list);
	}
	return (1);
}

int		ft_unset_stage(struct termios *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tcsetattr(0, 0, term); /* back to default values */
	tputs(tgetstr("me", NULL), 1, tputs_putchar);
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	return (1);
}

void	ft_return(t_clist **list)
{
	t_clist *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->is_selected)
		{
			ft_putstr(tmp->str);
			ft_putstr(" ");
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
}


int		main(int argc, char **argv)
{
	struct termios	term;
	t_window		size;
	t_clist			*list;

	(void)argv;
	if ((!ft_set_stage(argc, &term))||(!ft_get_size(&size)))
		return (-1);
	ft_signals();
	list = ft_get_list(argv);
	ft_print(&size, &list);
	if (ft_wait_for_input (&size ,&list))
	{
		ft_unset_stage(&term);
		ft_return(&list);
		ft_list_del(&list);
		return (1);
	}
	ft_unset_stage(&term);
	ft_list_del(&list);
	return (0);
}
