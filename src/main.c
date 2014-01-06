/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 09:59:59 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/06 10:10:47 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv, char **env)
{
	struct termios	term;
	char	buffer[2048];

	argc = 0;
	argv = 0;
	env = 0;
	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0,&term);
	return(0);
}

