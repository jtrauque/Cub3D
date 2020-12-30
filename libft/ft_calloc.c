/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:43:22 by jtrauque          #+#    #+#             */
/*   Updated: 2020/11/19 12:21:18 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*str;

	i = 0;
	if (!(str = malloc(size * count)))
		return (NULL);
	while (i < (size * count))
	{
		((char*)str)[i] = 0;
		i++;
	}
	return (str);
}
