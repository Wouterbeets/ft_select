/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 18:20:47 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



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

int		main(int argc, char **argv)
{
	struct termios	term;
	t_window		size;
	t_clist			*list;

	(void)argv;
	if ((!ft_set_stage(argc, &term))||(!ft_get_size(&size)))
		return (-1);
	list = ft_get_list(argv);
	ft_set_tabs(&size, &list);
//	ft_print(argc, argv);
	ft_printlist(list);
	ft_wait_for_input(&list);
	return (0);
}


