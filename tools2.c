/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:25 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 19:19:56 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char 	*ft_path(char *elements)
{
	int j;

	j = ft_strlen(elements);
	while (elements[j - 1] == ' ')
		j--;
	elements[j] = '\0';
	return (elements);
}
