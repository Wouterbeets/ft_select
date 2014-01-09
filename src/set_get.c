/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 17:32:26 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 12:59:55 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_get_size(t_window *size)
{
	struct winsize	ws;

	ioctl(FD ,TIOCGWINSZ, &ws);
	if ((size->co = (int)ws.ws_col/*tgetnum("co"))*/) < 0)
		return (-1);
	if ((size->li = ws.ws_row/*tgetnum("li"))*/) < 0)
		return (-1);
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

t_clist		*ft_get_list(char **argv)
{
	t_clist	*ret;
	int		i;

	i = 1;
	ret = ft_clstnew(argv[i]);
	i++;
	while (argv[i] != '\0')
	{
		ft_clstaddend(&ret, ft_clstnew(argv[i]));
		i++;
	}
	ret->is_cursor = 1;
	return (ret);
}

void	ft_putheader(t_window *size)
{
	tputs(tgetstr("cl", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 0), 1, tputs_putchar);
	ft_putstr_fd("  ____________________.____     __", FD);
	ft_putstr_fd("_____________________________", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 1), 1, tputs_putchar);
	ft_putstr_fd(" /   _____/\\_   _____/|    |    \\_  ", FD);
	ft_putstr_fd(" _____/\\_   ___ \\__    ___/", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 2), 1, tputs_putchar);
	ft_putstr_fd(" \\_____  \\  |    __)_ |    |     |    ", FD);
	ft_putstr_fd("__)_ /    \\  \\/ |    |   ", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 3), 1, tputs_putchar);
	ft_putstr_fd(" /        \\ |        \\|    |___  |    ", FD);
	ft_putstr_fd("    \\\\     \\____|    |   ", FD);
	tputs(tgoto(tgetstr("cm", NULL), size->co / 2 - 40, 4), 1, tputs_putchar);
	ft_putstr_fd("/________ //________ /|_______ / /_____", FD);
	ft_putstr_fd("___/ \\_______ /|____|   \n", FD);
	tputs(tgoto(CM, POSX, POSY),TPUTS_END);
}

int		tputs_putchar(int c)
{
    write(2, &c, 1);
    return (1);
}
