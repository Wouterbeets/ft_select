/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 17:15:33 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/08 13:33:17 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define CM tgetstr("cm", NULL)
# define HEADHEIGHT 5
# define POSY size->arg_printed + HEADHEIGHT
# define TPUTS_END 1, tputs_putchar
# define POSX (size->co / (size->num_tab + 2)) * size->tab_counter

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
	int	num_tab;
	int	max_len;
	int	arg_printed;
	int	listcount;
	int	items_per_tab;
	int	tab_counter;

}				t_window;

typedef struct		s_clist
{
	char			*str;
	struct s_clist	*next;
	struct s_clist	*prev;
	int				is_selected;
	int				is_cursor;
}					t_clist;

int		ft_maxlen(t_clist **list);
void	ft_clstadd(t_clist **alst, t_clist *new);
t_clist	*ft_clstnew(char *str);
void	ft_clstaddend(t_clist **alst, t_clist *new);
int		ft_clistcount(t_clist **alst);
t_clist	*ft_move_up(t_window *size, t_clist **list, t_clist *item);
t_clist	*ft_move_down(t_window *size, t_clist **list, t_clist *item);
t_clist	*ft_move_left(t_window *size, t_clist **list, t_clist *item);
t_clist	*ft_move_right(t_window *size, t_clist **list, t_clist *item);
int		is_rtn(char *buf);
int		is_arrow(char *buf);
int		ft_get_size(t_window *size);
int		tputs_putchar(int c);
int		ft_set_stage(int argc, struct termios *term);
int		ft_set_tabs(t_window *size, t_clist **list);
t_clist	*ft_get_list(char **argv);
void	ft_putheader(t_window *size);
void	ft_fill_struct_window(t_window *size, t_clist **list);
void	ft_print(t_window *size, t_clist **list);
int		is_space(char *buf);
t_clist	*ft_select(t_window *size, t_clist **list, t_clist *item);

#endif
