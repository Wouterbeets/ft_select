/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 18:46:50 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 14:47:36 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_maxlen(t_clist **list)
{
	int		i;
	int		len;
	t_clist	*ls;

	len = 0;
	i = 0;
	ls = *list;
	while (ls->next != NULL)
	{
		while (ls->str[i] != '\0')
		{
			if (i > len)
				len = i;
			i++;
		}
		ls = ls->next;
		i = 0;
	}
	return (len + 1);
}
