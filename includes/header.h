/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 17:15:33 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 16:17:20 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <signal.h>
# include <term.h>
# include "libft.h"

typedef struct	s_window
{
	int	li;
	int	co;
}				t_window;

typedef struct		s_clist
{
	char			*str;
	struct s_clist	*next;
	struct s_clist	*prev;
	int				col;
	int				line;
	int				selected;
}					t_clist;

int		ft_maxlen(t_clist **list);
void	ft_clstadd(t_clist **alst, t_clist *new);
t_clist	*ft_clstnew(char *str);
void	ft_clstaddend(t_clist **alst, t_clist *new);
int		ft_clistcount(t_clist **alst);

#endif
