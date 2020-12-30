/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:10:03 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/20 17:11:24 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = (char*)s;
	if (c == '\0')
		return (t + ft_strlen(t));
	else
		while (t[i])
		{
			if (t[i] == c)
				return (t + i);
			i++;
		}
	return (NULL);
}
