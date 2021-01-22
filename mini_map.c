/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:55:33 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/22 18:34:29 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cadre(t_pars *pars, int x, int y, int color)
{
	t_mini mini;

	mini.size_x = (pars->width / 5) / pars->params->map_w;
	mini.size_y = (pars->height / 5) / pars->params->map_h;
	mini.x_max = (x + 1) * mini.size_x;
	mini.y = y * mini.size_y;
	mini.y_max = mini.y + mini.size_y;
	while (mini.y < mini.y_max)
	{
		mini.x = x * mini.size_x;
		while (mini.x < mini.x_max)
		{
			ft_put_px_in_image(&pars->params->data, mini.x, mini.y, color);
			mini.x++;
		}
		mini.y++;
	}
}

void	ft_mini_map(t_pars *pars, t_params *params)
{
	int x;
	int y;

	y = 0;
	while (y < params->map_h)
	{
		x = 0;
		while (x < params->map_w)
		{
			if (pars->map[y][x] == '1')
				ft_cadre(pars, x, y, 0);
			else if (pars->map[y][x] == '2')
				ft_cadre(pars, x, y, 0x900C3F);
			else if (pars->map[y][x] == '3')
				ft_cadre(pars, x, y, 0xFF5733);
			else
				ft_cadre(pars, x, y, 0xB0A4AB);
			x++;
		}
		y++;
	}
	ft_cadre(pars, pars->px, pars->py, 0x08186B);
}
