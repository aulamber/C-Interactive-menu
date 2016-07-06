/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:03:36 by aulamber          #+#    #+#             */
/*   Updated: 2014/04/15 16:03:38 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char			*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		s1_len;

	if (s1 && s2)
	{
		i = 0;
		s1_len = ft_strlen(s1);
		while (s2[i] != '\0')
		{
			s1[s1_len] = s2[i];
			i++;
			s1_len++;
		}
		s1[s1_len] = '\0';
		return (s1);
	}
	return (s1);
}
