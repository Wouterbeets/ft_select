/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 17:05:23 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/06 19:50:46 by wbeets           ###   ########.fr       */
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
	char	*str;
	
	if (!(max_len_tab = ft_maxlen(list)))
		return (-1);
	i = 0;
	j = -1;
	while ((size->li / ++i) < (argc -1))
		;
	if (i * max_len_tab > size->co)
		ft_putendl("please resize window to display everyting");
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	while (++j <= i)
	{
		max_len_tab = max_len_tab * j;
		str = tgetstr("cm", NULL);
		ft_putstr(str);
		tputs(str, 1, tputs_putchar);
		ft_putchar('x');
	}
	return (1);
}



int		main(int argc, char **argv)
{
	struct termios	term;
	t_window		size;

	(void)argv;
	if ((!ft_set_stage(argc, &term))||(!ft_get_size(&size)))
		return (-1);
	ft_set_tabs(&size, argv, argc);
//	ft_print(argc, argv);
//	ft_wait_for_input();
	return (0);
}

