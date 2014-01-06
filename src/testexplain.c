/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 09:59:59 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/06 14:37:22 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
int		main(int argc, char **argv)
{
	struct termios	term;
	char	buffer[2048];

	argc = 0;
	argv = 0;
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag &= ECHO;  prevents a char from being output when pressedi
	term.c_lflag &= ICANON; each char is treated independently 
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	return(0);
}
*/

int tputs_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int main(void)
{
    char    				buffer[2048];
    struct termios		term;
    char					read_char[5] = {0};

    if (tgetent(buffer, getenv("TERM")) < 1)
        return (-1);
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON); /* each char is treated independently */
	term.c_lflag &= ~(ECHO); /* prevents a char from being output when pressed*/
	term.c_cc[VMIN] = 1; /* see Samy's explanations further down the topic */
	term.c_cc[VTIME] = 0; /* ^ */
    tcsetattr(0, 0, &term);
    tputs(tgetstr("ti", NULL), 1, tputs_putchar); /* opens cup */
    tputs(tgetstr("mr", NULL), 1, tputs_putchar); /* turns on reverse video */
    write(1, "reverse video", 13);
    tputs(tgetstr("me", NULL), 1, tputs_putchar); /* turns off all */
    tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
    write(1, "normal", 7);
	tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
    while (read_char[0] == 0)
        read(0, read_char, 4);
    tputs(tgetstr("te", NULL), 1, tputs_putchar); /* closes cup */
    term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
    tcsetattr(0, 0, &term); /* back to default values */
    return (0);
}
