/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <aulamber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:01:04 by aulamber          #+#    #+#             */
/*   Updated: 2014/05/02 16:23:50 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s2)
	{
		while (i < n)
		{
			*((unsigned char *)s1 + i) = *((unsigned char *)s2 + i);
			i++;
		}
		return (s1);
	}
	else
		return (0);
}
