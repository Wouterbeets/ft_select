/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 14:54:12 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/06 17:05:09 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}
int	main(int argc, char **argv)
{
	int				i;
	char			read_char[5] = {0};
	char			buffer[2048];
	struct termios	term;
	int				height;
	int				width;

	i = 0;
	if (argc < 2)
	{
		ft_putstr("usage: ft_select, choice1 choice2 etc.");
		return (-1);
	}
	else
	{
		if (tgetent(buffer, getenv("TERM")) < 1)
			return (-1);
		tcgetattr(0, &term);
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		tcsetattr(0, 0, &term);
		a = tgetflag("bv");
		while (argv[++i] != '\0')
		{
			height = tgetnum("li");
			width = tgetnum("co");

			tputs(tgetstr("ti", NULL), 1, tputs_putchar);
			tputs(tgetstr("mr", NULL), 1, tputs_putchar);
			ft_putendl(argv[i]);
		}
		while (read_char[0] == 0)
		{
			read(0, read_char, 4);
			ft_putnbr(read_char[0]);
			ft_putchar('\t');
			ft_putnbr(read_char[1]);
			ft_putchar('\t');
			ft_putnbr(read_char[2]);
			ft_putchar('\t');
			ft_putnbr(read_char[3]);
			ft_putchar('\n');
		}
	}
	return (0);
}

