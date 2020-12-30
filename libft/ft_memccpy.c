/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:47:08 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/16 12:45:46 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	a;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s[i] == a)
		{
			d[i] = s[i];
			return (d + i + 1);
		}
		else
		{
			d[i] = s[i];
			i++;
		}
	}
	return (NULL);
}
