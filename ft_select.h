/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 19:47:40 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/04 21:47:03 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# define ENT 2
# define EXIT 1

typedef struct		s_list
{
	char			*arg;
	int				rev;
	int				curs;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_env
{
	struct termios	orig;
	struct termios	act;
}					t_env;

t_list				*list_new(char *arg);
void				list_print_begin(t_list *list);
t_list				*list_add_end(t_list *list, t_list *newl);
t_list				*list_remove(t_list *node);
void				move_curse(t_list *list, int fun);
void				print_ft_list(t_list *list);
int					tputs_putchar(int c);
void				select_list(t_list *list);
void				restore_term(t_env *envir);
int					init_shell(t_env *envir);
char				*tab_zero(char *read_char);
t_list				*list_begin(t_list *list);
char				*wait_key(char *read_c, t_list **list, t_env *envir);
void				ft_which_key(char *k, t_list **list, t_env *envir);
void				ft_del(t_list **list);
void				ft_enter(t_list **list, t_env *envir);

#endif
