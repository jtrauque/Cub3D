/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:49:57 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/19 19:26:40 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (!s2 || !s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] && i < len)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
