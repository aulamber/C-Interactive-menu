/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:05:37 by aulamber          #+#    #+#             */
/*   Updated: 2014/04/15 16:05:39 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *s)
{
	char	*str;

	if (s == NULL)
		return (0);
	str = (char*)s;
	while (*str)
		str++;
	return (str - s);
}
