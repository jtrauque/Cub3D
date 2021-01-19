/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:51:34 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/19 19:24:51 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*s2;
	int		i;
	int		j;

	i = (int)start;
	j = 0;
	if (!s)
	{
		return (NULL);
		if (!(s2 = malloc(sizeof(char) * (1))))
			return (NULL);
		s2[j] = '\0';
		return (s2);
	}
	if (!(s2 = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start <= ft_strlen(s))
		while (s[i] && j < len)
			s2[j++] = s[i++];
	s2[j] = '\0';
	return (s2);
}
