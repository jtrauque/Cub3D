/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:51:02 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/18 13:33:06 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;
	char	*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (!*needle || haystack == needle)
		return (h);
	while (*h && i < len)
	{
		if (ft_strncmp(h + i, n, ft_strlen(n)) == 0)
		{
			if (((i + ft_strlen(n)) > len))
				return (NULL);
			return (h + i);
		}
		else
			i++;
	}
	return (NULL);
}
