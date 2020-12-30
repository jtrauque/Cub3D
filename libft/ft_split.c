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

#include "libft.h"

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

static int		ft_count_char(char const *s, char c, int i)
{
	int count;

	count = 0;
	while (s[i])
	{
		if (ft_equal(s[i], c) != 0)
			break ;
		i++;
		count++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
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
		if (!(word[j] = malloc(sizeof(char) * (ft_count_char(s, c, i) + 1))))
			return (NULL);
		ft_memcpy(word[j], s + i, ft_count_char(s, c, i));
		word[j++][ft_count_char(s, c, i)] = '\0';
		i += ft_count_char(s, c, i);
	}
	word[j] = 0;
	return (word);
}
