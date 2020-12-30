/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:49:34 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/16 13:00:46 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
