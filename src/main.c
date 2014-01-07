/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 17:08:40 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_size(t_window *size)
{
	if((size->co = tgetnum("co")) < 1)
		return (-1);
	if((size->li = tgetnum("li")) < 1)
		return (-1);
	return (1);
}

int tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}


int		ft_set_stage(int argc, struct termios *term)
{
	char			buffer[2048];

	if (argc < 2)
	{
		ft_putstr("usage: ft_select, choice1 choice2 etc.");
		return (-1);
	}
	else
	{
		if (tgetent(buffer, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, term);
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ECHO);
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
		tcsetattr(0, 0, term);
	}
	return (1);
}


int		ft_set_tabs(t_window *size, t_clist **list)
{
	int	max_len_tab;
	int	i;
	int	j;
	int tmp;

	if (!(max_len_tab = ft_maxlen(list) + 5))
		return (-1);
	i = 1;
	j = 1;
	while (size->li < ft_clistcount(list) / i)
		i++;
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	while (j < i)
	{
		tmp = max_len_tab;
		max_len_tab = max_len_tab * j;
		tputs(tgoto(tgetstr("cm", NULL), max_len_tab, 0), 1, tputs_putchar);
		tputs(tgetstr("st", NULL), 1, tputs_putchar);
		j++;
		max_len_tab = tmp;
	}
	return (1);
}

t_clist	*ft_get_list(char **argv)
{
	t_clist	*ret;
	int		i;

	i = 1;
	ret = ft_clstnew(argv[i++]);
	while (argv[i] != '\0')
	{
		ft_clstadd(&ret, ft_clstnew(argv[i]));
		i++;
	}
	return (ret);
}

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


int		ft_wait_for_input(t_clist **list)
{
	char	read_char[4];
	int		direction;

	while (!(is_rtn(read_char)))
	{
		read(0, read_char, 3);
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
	ft_wait_for_input(&list);
	return (0);
}
/*
void	ft_printlist(t_clist *list)
{
	t_clist	*tmp;

	tmp = list;
	while (tmp->next != NULL)
	{
		ft_putendl((char *)tmp->str);
		tmp = tmp->next;
	}
}
*/
