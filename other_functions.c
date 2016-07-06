/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/04 20:18:57 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/04 20:54:30 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <termcap.h>
#include "ft_select.h"

void			restore_term(t_env *envir)
{
	tputs(tgetstr("ve", NULL), ENT, tputs_putchar);
	tputs(tgetstr("te", NULL), ENT, tputs_putchar);
	tcsetattr(0, TCSANOW, &envir->act);
}

int				init_shell(t_env *envir)
{
	char		buffer[2048];

	if (tgetent(buffer, "linux") < 1)
		return (-1);
	if (tcgetattr(1, &envir->act) != 0)
		return (-1);
	envir->act.c_lflag &= ~(ECHO | ICANON);
	envir->act.c_cc[VMIN] = 1;
	envir->act.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &envir->act);
	tputs(tgetstr("ti", NULL), ENT, tputs_putchar);
	tputs(tgetstr("vi", NULL), ENT, tputs_putchar);
	return (0);
}
