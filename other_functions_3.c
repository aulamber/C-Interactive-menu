/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 20:39:58 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/04 20:40:03 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_select.h"
#include "libft/libft.h"
#include <termios.h>
#include <termcap.h>

char				*tab_zero(char *read_char)
{
	int				i;

	i = 0;
	while (read_char[i])
	{
		read_char[i] = 0;
		i++;
	}
	return (read_char);
}

void				move_curse(t_list *list, int fun)
{
	t_list			*tmp;
	t_list			*save;

	save = list;
	tmp = NULL;
	while (list->curs != 1)
	{
		tmp = list;
		list = list->next;
	}
	if (fun == 1)
	{
		if (tmp == NULL)
		{
			tmp = list;
			while (tmp->next)
				tmp = tmp->next;
		}
		tmp->curs = 1;
	}
	else if (list->next)
		list->next->curs = 1;
	else
		save->curs = 1;
	list->curs = 0;
}

void				print_ft_list(t_list *list)
{
	tputs(tgetstr("cl", NULL), ENT, tputs_putchar);
	while (list)
	{
		if (list->curs)
			tputs(tgetstr("us", NULL), ENT, tputs_putchar);
		if (list->rev == 1)
			tputs(tgetstr("mr", NULL), ENT, tputs_putchar);
		ft_dprintf(ENT, "%s\n", list->arg);
		if (list->rev == 1)
			tputs(tgetstr("me", NULL), ENT, tputs_putchar);
		if (list->curs)
			tputs(tgetstr("ue", NULL), ENT, tputs_putchar);
		list = list->next;
	}
	tputs(tgetstr("me", NULL), ENT, tputs_putchar);
	while (list)
	{
		tputs(tgetstr("up", NULL), ENT, tputs_putchar);
		list = list->prev;
	}
	tputs(tgetstr("te", NULL), ENT, tputs_putchar);
}

int					tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void				select_list(t_list *list)
{
	t_list			*tmp;

	tmp = list;
	while (tmp->curs != 1)
		tmp = tmp->next;
	tmp->rev = (tmp->rev) ? 0 : 1;
	tmp->curs = 0;
	if (tmp->next)
		tmp->next->curs = 1;
	else
		list->curs = 1;
}
