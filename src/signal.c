/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:15:36 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/09 13:01:26 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"




void	resize(int i)
{
	char	str[2];

	(void)i;
	str[0] = -62;
	str[1] = '\0';
	ioctl(FD, TIOCSTI, str);
}



void	ft_signals()
{
	signal(SIGWINCH, &resize);
//	signal(SIGSEGV, segv);
//	signal(SIGTSTP, tempstop);
//	signal(SIGCONT, resume);
//	signal(SIGSTOP, stop);
}
