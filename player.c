/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 22:04:22 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/23 15:51:16 by jtrauque         ###   ########.fr       */
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

void		ft_count_sprite(t_pars *pars, char c)
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
			if (pars->map[y][x] == c)
			{
				i++;
			}
			x++;
		}
		y++;
	}
	if (c == '2')
		pars->sprite_nbr = i;
	if (c == '3')
		pars->sprite_bonus_nbr = i;
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
		pars->sprite[i].text = 2;
	}
}

int			ft_loc_sprite_bonus(t_pars *pars)
{
	t_vecteur	s;
	int			i;

	i = 0;
	ft_memset(&s, 0, sizeof(t_vecteur));
	ft_count_sprite(pars, '3');
	if (!(pars->sprite_bonus = malloc(sizeof(t_vecteur) *
					(pars->sprite_bonus_nbr))))
		return (0);
	while (pars->map[s.y])
	{
		s.x = 0;
		while (pars->map[s.y][s.x])
		{
			if (pars->map[s.y][s.x] == '3')
			{
				pars->sprite_bonus[i].y = (float)s.y + .5;
				pars->sprite_bonus[i].x = (float)s.x + .5;
				i++;
			}
			s.x++;
		}
		s.y++;
	}
	return (1);
}

int			ft_location_player(t_pars *pars)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	ft_count_sprite(pars, '2');
	if (!(pars->sprite = malloc(sizeof(t_vecteur) * (pars->sprite_nbr))))
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
	ft_loc_sprite_bonus(pars);
	if (pars->sprite_bonus_nbr != 0)
		ft_join_sprite_bonus(pars);
	return (1);
}
