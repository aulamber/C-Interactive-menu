/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/01 18:45:25 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/04 21:45:49 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_select.h"
#include "libft/libft.h"

t_list		*list_new(char *arg)
{
	t_list	*tmp;

	tmp = NULL;
	if ((tmp = malloc(sizeof(t_list))))
	{
		tmp->arg = arg;
		tmp->curs = 0;
		tmp->rev = 0;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	return (tmp);
}

void		list_print_begin(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", list->arg);
		list = list->next;
	}
}

t_list		*list_add_end(t_list *list, t_list *newl)
{
	t_list	*tmp;

	if (list)
	{
		tmp = list;
		while (list && list->next)
			list = list->next;
		list->next = newl;
		newl->prev = list;
		return (tmp);
	}
	newl->curs = 1;
	return (newl);
}

t_list		*list_begin(t_list *list)
{
	while (list && list->prev)
		list = list->prev;
	return (list);
}

t_list		*list_remove(t_list *node)
{
	t_list	*tmp;

	if (node->prev == NULL)
	{
		tmp = node->next;
		free(node);
		if (tmp)
			tmp->prev = NULL;
	}
	else if (node->next == NULL)
	{
		tmp = node->prev;
		free(node);
		tmp->next = NULL;
	}
	else
	{
		tmp = node;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp = tmp->prev;
		free(node);
	}
	return (list_begin(tmp));
}
