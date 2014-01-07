/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 14:17:58 by wbeets           ###   ########.fr       */
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


int		ft_set_tabs(t_window *size, char **list, int argc)
{
	int	max_len_tab;
	int	i;
	int	j;
	int tmp;

	if (!(max_len_tab = ft_maxlen(list) + 5))
		return (-1);
	i = 1;
	j = 1;
	while (size->li < (argc -1) / i)
		i++;
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	ft_putchar('x');
	while (j < i)
	{
		tmp = max_len_tab;
		max_len_tab = max_len_tab * j;
		tputs(tgoto(tgetstr("cm", NULL), max_len_tab, 0), 1, tputs_putchar);
		ft_putchar('x');
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


int		main(int argc, char **argv)
{
	struct termios	term;
	t_window		size;
	t_clist			*list;

	(void)argv;
	if ((!ft_set_stage(argc, &term))||(!ft_get_size(&size)))
		return (-1);
	list = ft_get_list(argv);
//	ft_printlist(list);
	ft_set_tabs(&size, argv, argc);
//	ft_print(argc, argv);
//	ft_wait_for_input();
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
