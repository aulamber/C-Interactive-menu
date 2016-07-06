/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:00:47 by aulamber          #+#    #+#             */
/*   Updated: 2014/04/15 16:00:49 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	if (s)
	{
		str = s;
		while (n-- > 0)
		{
			if (*str == (unsigned char)c)
				return ((void *)str);
			str++;
		}
	}
	return (NULL);
}
