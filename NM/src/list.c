/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 07:37:18 by lstreak           #+#    #+#             */
/*   Updated: 2018/08/03 10:31:50 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void		list_print_64(t_sym **head)
{
	t_sym	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->type != 'z' && tmp->value == 0 && tmp->type != 'T')
		{
			ft_printf("                 ");
			ft_printf("%c ", tmp->type);
			ft_printf("%s\n", tmp->name);
		}
		else if (tmp->type != 'z')
		{
			ft_printf("%.16llx ", tmp->value);
			ft_printf("%c ", tmp->type);
			ft_printf("%s\n", tmp->name);
		}
		tmp = tmp->next;
	}
}

void		list_print_32(t_sym **head)
{
	t_sym	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->type != 'z' && tmp->value == 0 && tmp->type != 'T')
		{
			ft_printf("         ");
			ft_printf("%c ", tmp->type);
			ft_printf("%s\n", tmp->name);
		}
		else if (tmp->type != 'z')
		{
			ft_printf("%.16llx ", tmp->value);
			ft_printf("%c ", tmp->type);
			ft_printf("%s\n", tmp->name);
		}
		tmp = tmp->next;
	}
}

void		list_push(t_sym **head, uint64_t value, uint8_t type, char *name)
{
	t_sym	*new;

	if (!(new = (t_sym *)malloc(sizeof(*new))))
		ft_putendl_fd("Malloc failed!", 2);
	new->value = value;
	new->type = type;
	new->name = ft_strdup(name);
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
		list_find_end(*head)->next = new;
}

t_sym		*list_find_end(t_sym *head)
{
	if (head->next == NULL)
		return (head);
	else
		return (list_find_end(head->next));
}
