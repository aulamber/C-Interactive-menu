/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:03:11 by aulamber          #+#    #+#             */
/*   Updated: 2014/04/26 20:22:34 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		write(1, "NULL", 4);
	else
	{
		i = ft_strlen(s);
		write(1, s, i);
	}
	return (i);
}
