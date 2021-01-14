/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:36:07 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/14 23:35:12 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_space(char *elements)
{
	int i;

	i = 0;
	while (elements[i])
	{
		if (elements[i] == ' ')
			i++;
		else
			return (i);
	}
	return (-1);
}

void	ft_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	exit(1);
}

void	ft_error_map(char *str, t_pars *pars)
{
	int i;

	i = 0;
	ft_putstr("Error\n");
	ft_putstr(str);
	while (pars->map[i])
	{
		free(pars->map[i]);
		i++;
	}
	exit(1);
}
