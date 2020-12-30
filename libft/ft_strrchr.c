/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:51:13 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/16 13:13:08 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;
	char	d;

	i = ft_strlen(s);
	t = (char*)s;
	d = (char)c;
	if (c == '\0')
		return (t + i);
	else
		while (i >= 0)
		{
			if (t[i] == d)
				return (t + i);
			i--;
		}
	return (NULL);
}
