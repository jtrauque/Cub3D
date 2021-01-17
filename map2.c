/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:58:18 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/17 21:40:03 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_column(t_pars *pars, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	while (i < params->map_w)
	{
		j = 0;
		while (j < params->map_h - 1)
		{
			if ((pars->map[j][i] == '0' || pars->map[j][i] == '2')
				&& pars->map[j + 1][i] == ' ')
				return (0);
			if (pars->map[j][i] == ' ' && (pars->map[j + 1][i] == '0'
				|| pars->map[j + 1][i] == '2'))
				return (0);
			if (pars->map[j][i] == ' ')
				pars->map[j][i] = '1';
			j++;
		}
		i++;
	}
	return (ft_check_walls(pars, params));
}

int			ft_check_walls_column(t_pars *pars, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < params->map_h)
	{
		if (pars->map[i][0] != '1' && pars->map[i][0] != ' ')
			return (ft_error("map error - wall missing\n"));
		i++;
	}
	while (j < params->map_h)
	{
		if (pars->map[j][params->map_w - 1] != '1'
			&& pars->map[j][params->map_w - 1] != ' ')
			return (ft_error("map error - wall missing\n"));
		j++;
	}
	return (1);
}
