/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:51:26 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/19 14:21:56 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_count(char const *s1, char const *set)
{
	int	i;
	int j;

	i = 0;
	j = ft_strlen(s1);
	while (ft_find_set(s1[i], set) != 0)
		i++;
	if (s1[i])
	{
		while (ft_find_set(s1[j - 1], set) != 0)
			j--;
	}
	return (j - i);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && ft_find_set(s1[i], set) != 0)
		i++;
	if (!(str = malloc(sizeof(char) * (ft_count(s1, set) + 1))))
		return (NULL);
	while (j < ft_count(s1, set))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
