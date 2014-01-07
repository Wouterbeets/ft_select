/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:32:26 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 18:38:39 by wbeets           ###   ########.fr       */
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

int		tputs_putchar(int c)
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

void	ft_putheader()
{
	ft_putstr("  ____________________.____     __");
	ft_putstr("_____________________________\n");
	ft_putstr(" /   _____/\\_   _____/|    |    \\_  ");
	ft_putstr(" _____/\\_   ___ \\__    ___/\n");
	ft_putstr(" \\_____  \\  |    __)_ |    |     |    ");
	ft_putstr("__)_ /    \\  \\/ |    |   \n");
	ft_putstr(" /        \\ |        \\|    |___  |    ");
	ft_putstr("    \\\\     \\____|    |   \n");
	ft_putstr("/________ //________ /|_______ / /_____");
	ft_putstr("___/ \\_______ /|____|   \n");
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
		j++;
		max_len_tab = tmp;
	}
	ft_putheader();
	return (1);
}

t_clist		*ft_get_list(char **argv)
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
