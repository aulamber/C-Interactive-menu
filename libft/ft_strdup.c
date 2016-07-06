/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 16:04:37 by aulamber          #+#    #+#             */
/*   Updated: 2014/04/15 16:04:38 by aulamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (s1)
	{
		str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
