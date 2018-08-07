/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:37:28 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/03 10:32:00 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_sym		*list_switch(t_sym *l, t_sym *r)
{
	l->next = r->next;
	r->next = l;
	return (r);
}

void		list_cmp(t_sym **p, t_sym **q, t_sym **top, int *changed)
{
	*changed = 0;
	*q = *top;
	*p = (*top)->next;
	while ((*p)->next != NULL)
	{
		if (strcmp((*p)->name, (*p)->next->name) > 0)
		{
			(*q)->next = list_switch(*p, (*p)->next);
			*changed = 1;
		}
		*q = *p;
		if ((*p)->next != NULL)
			*p = (*p)->next;
	}
}

t_sym		*list_sort(t_sym *head)
{
	t_sym	*p;
	t_sym	*q;
	t_sym	*top;
	int		changed;

	changed = 1;
	if (!(top = malloc(sizeof(*top))))
		ft_putendl_fd("Malloc failed", 2);
	top->next = head;
	while (changed)
	{
		list_cmp(&p, &q, &top, &changed);
	}
	p = top->next;
	free(top);
	return (p);
}
