/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:04:22 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 17:21:44 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_direction(t_pars *pars, char c)
{
	if (c == 'N')
	{
		pars->dy = -1.0;
		pars->plane_x = 1.0;
	}
	else if (c == 'S')
	{
		pars->dy = 1.0;
		pars->plane_x = -1.0;
	}
	else if (c == 'W')
	{
		pars->dx = -1.0;
		pars->plane_y = -1.0;
	}
	else if (c == 'E')
	{
		pars->dx = 1.0;
		pars->plane_y = 1.0;
	}
}

void		ft_count_sprite(t_pars *pars)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (pars->map[y])
	{
		x = 0;
		while (pars->map[y][x])
		{
			if (pars->map[y][x] == '2')
			{
				i++;
			}
			x++;
		}
		y++;
	}
	pars->sprite_nbr = i;
}

void		ft_save_location(t_pars *pars, int x, int y, int i)
{
	if (ft_find_orientation(pars->map[y][x], "NSWE") == 1)
	{
		pars->py = (float)y + .5;
		pars->px = (float)x + .5;
		ft_direction(pars, pars->map[y][x]);
	}
	if (pars->map[y][x] == '2')
	{
		pars->sprite[i].y = (float)y + .5;
		pars->sprite[i].x = (float)x + .5;
	}
}

int		ft_location_player(t_pars *pars)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	ft_count_sprite(pars);
	if (!(pars->sprite = malloc(sizeof(t_vecteur) * (pars->sprite_nbr + 1))))
		return (0);
	while (pars->map[y])
	{
		x = 0;
		while (pars->map[y][x])
		{
			ft_save_location(pars, x, y, i);
			if (pars->map[y][x] == '2')
				i++;
			x++;
		}
		y++;
	}
	return (1);
}
