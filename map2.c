/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:58:18 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/15 19:59:15 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_check_walls_column(t_pars *pars, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < params->map_h)
	{
		if (pars->map[i][0] != '1')
			ft_error_map("map error - wall missing\n", pars);
		i++;
	}
	while (j < params->map_w)
	{
		if (pars->map[j][params->map_w - 1] != '1')
			ft_error_map("map error - wall missing\n", pars);
		j++;
	}
}
