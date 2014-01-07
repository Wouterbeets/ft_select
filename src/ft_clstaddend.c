/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 11:08:56 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/07 14:10:33 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clstaddend(t_clist **alst, t_clist *new)
{
	t_clist	*tmp;
	
	tmp = *alst;
	while(tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
