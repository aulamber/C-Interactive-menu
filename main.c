/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 19:52:18 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/04 21:27:03 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <stdlib.h>
#include "ft_select.h"
#include "libft/libft.h"

void				ft_enter(t_list **list, t_env *envir)
{
	restore_term(envir);
	while (*list && (*list)->rev != 1)
		*list = (*list)->next;
	if (*list)
	{
		ft_dprintf(EXIT, "%s", (*list)->arg);
		*list = (*list)->next;
	}
	while (*list)
	{
		if ((*list)->rev == 1)
			ft_dprintf(EXIT, " %s", (*list)->arg);
		*list = (*list)->next;
	}
}

void				ft_del(t_list **list)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp->curs != 1)
		tmp = (tmp)->next;
	if ((tmp)->next)
		move_curse(*list, 0);
	else
		move_curse(*list, 1);
	*list = list_remove(tmp);
}

void				ft_which_key(char *k, t_list **list, t_env *envir)
{
	if (*(int*)k == 27)
	{
		restore_term(envir);
		exit(EXIT_SUCCESS);
	}
	else if (*(int*)k == 10)
		ft_enter(list, envir);
	else if (ft_strcmp(k, tgetstr("ku", NULL)) == 0)
	{
		ft_dprintf(ENT, "%s\n", k);
		move_curse(*list, 1);
	}
	else if (ft_strcmp(k, tgetstr("kd", NULL)) == 0)
		move_curse(*list, 0);
	else if (ft_strcmp(k, " ") == 0)
		select_list(*list);
	else if ((ft_strcmp(k, "\177") == 0) || *(int*)k == 2117294875)
		ft_del(list);
}

char				*wait_key(char *read_c, t_list **list, t_env *envir)
{
	while (read(0, read_c, 4) && *list)
	{
		read_c[4] = 0;
		ft_which_key(read_c, list, envir);
		ft_bzero(read_c, 4);
		if (*list)
			print_ft_list(*list);
		else
			break ;
	}
	return (read_c);
}

int					main(int ac, char **av)
{
	t_env			envir;
	char			read_char[5];
	t_list			*list;
	int				i;

	tab_zero(read_char);
	i = 1;
	list = NULL;
	if (ac > 1)
	{
		while (i < ac)
		{
			list = list_add_end(list, list_new(av[i]));
			i++;
		}
		i = 1;
	}
	init_shell(&envir);
	print_ft_list(list);
	wait_key(read_char, &list, &envir);
	restore_term(&envir);
	exit(EXIT_SUCCESS);
	return (0);
}
