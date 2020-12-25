/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:49:25 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/18 14:10:25 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		ft_equal(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int		ft_count_word(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] && s[i + 1])
	{
		if (s[i + 1] == c)
			count++;
		i++;
	}
	return (count + 1);
}

int ft_memcpy_one(char *dst, char *src, int n)
{
	int i;
	int count;

	i = 0;
	while (src[i] != '\n' && src[i] != '\0' && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	count = i;
	while (i < n)
	{
		dst[i] = '1';
		i++;
	}
	return (count);
}

char			**ft_split_one(char *s, char c, t_params *params)
{
	int		i;
	int		j;
	int		n;
	char	**word;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(word = malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && ft_equal(s[i], c) != 0)
			i++;
		if (!s[i])
			break ;
		if (!(word[j] = malloc(sizeof(char) * (params->map_w + 1))))
			return (NULL);
		n = ft_memcpy_one(word[j], s + i, params->map_w);
		word[j++][params->map_w] = '\0';
		i += n;
	}
	word[j] = 0;
	params->map_h = j;
	return (word);
}
