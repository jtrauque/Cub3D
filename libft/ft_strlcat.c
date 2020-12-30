/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:50:07 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/19 15:53:00 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_size_strlen(char *str, size_t dstsize)
{
	size_t i;

	i = 0;
	while (str[i] && i < dstsize)
		i++;
	return (i);
}

size_t				ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_size_strlen(dst, dstsize);
	j = 0;
	len = ft_size_strlen(dst, dstsize) + ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[j] && (i < dstsize - 1))
		dst[i++] = src[j++];
	if (dstsize != 0 && i < dstsize)
		dst[i] = '\0';
	return (len);
}
