/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 16:26:45 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 14:10:34 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_clist	*ft_clstnew(char *str)
{
	t_clist	*newlist;

	newlist = (t_clist *)malloc(sizeof(t_clist));
	if (newlist == NULL)
		return (NULL);
	if (str == NULL)
		newlist->str = NULL;
	else
		newlist->str = ft_strdup(str);;
	newlist->next = NULL;
	return (newlist);
}
