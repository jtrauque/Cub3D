/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:17:34 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 17:23:28 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite_init(t_pars *pars, t_sprite *sprite)
{
	sprite->init = 1.0 / (pars->plane_x * pars->dy - pars->dx * pars->plane_y);
	sprite->next_x = sprite->init * (pars->dy * sprite->sprite_x - pars->dx *
			sprite->sprite_y);
	sprite->next_y = sprite->init * (-pars->plane_y * sprite->sprite_x +
			pars->plane_x * sprite->sprite_y);
	sprite->sprite_screen = (int)((pars->width / 2) * (1 + sprite->next_x /
				sprite->next_y));
	sprite->heigth_column = abs((int)(pars->height / sprite->next_y));
	sprite->draw_start = (-sprite->heigth_column / 2) + (pars->height / 2);
	sprite->draw_end = (sprite->heigth_column / 2) + (pars->height / 2);
	if (sprite->draw_start < 0)
		sprite->draw_start = 0;
	if (sprite->draw_end >= pars->height)
		sprite->draw_end = pars->height - 1;
	sprite->width_column = abs((int)(pars->height / sprite->next_y));
	sprite->width_draw_start = (-sprite->width_column / 2) +
		sprite->sprite_screen;
	sprite->width_draw_end = (sprite->width_column / 2) +
		sprite->sprite_screen;
	if (sprite->width_draw_start < 0)
		sprite->width_draw_start = 0;
	if (sprite->width_draw_end >= pars->width)
		sprite->width_draw_end = pars->width - 1;
}

void	ft_sort_sprite(t_pars *pars)
{
	int			i;
	int			first;
	int			second;
	t_vecteur	tmp;

	i = 0;
	while (i < pars->sprite_nbr)
	{
		first = ((pars->px - pars->sprite[i].x) * (pars->px -
					pars->sprite[i].x) + (pars->py - pars->sprite[i].y) *
				(pars->py - pars->sprite[i].y));
		second = ((pars->px - pars->sprite[i + 1].x) * (pars->px -
					pars->sprite[i + 1].x) + (pars->py - pars->sprite[i + 1].y)
				* (pars->py -
					pars->sprite[i + 1].y));
		if (first < second)
		{
			tmp = pars->sprite[i];
			pars->sprite[i] = pars->sprite[i + 1];
			pars->sprite[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_print_sprite_column(t_sprite *s, t_pars *pars, t_params *params)
{
	int color;
	int n;

	n = s->start * pars->text_sprite.size_line - pars->height *
		(pars->text_sprite.size_line / 2) +
		s->heigth_column * (pars->text_sprite.size_line / 2);
	s->draw_y = ((n * pars->text_sprite.img_height) /
			s->heigth_column) / pars->text_sprite.size_line;
	color = ft_get_px_from_image(&pars->text_sprite, s->draw_x
			, s->draw_y);
	if (color != 0)
		ft_put_px_in_image(&params->data, s->stripe, s->start, color);
}

void	ft_sprite_loop(t_pars *pars, t_sprite *s, t_params *params)
{
	s->sprite_x = pars->sprite[s->n].x - (pars->px - .5);
	s->sprite_y = pars->sprite[s->n].y - (pars->py - .5);
	ft_sprite_init(pars, s);
	s->stripe = s->width_draw_start;
	while (s->stripe < s->width_draw_end)
	{
		s->draw_x = (int)(pars->text_sprite.size_line * (s->stripe -
					(-s->width_column / 2 + s->sprite_screen)) *
				pars->text_sprite.img_width / s->width_column) /
			pars->text_sprite.size_line;
		if (s->next_y > 0 && s->stripe > 0 && s->stripe < pars->width)
		{
			s->start = s->draw_start;
			while (s->start < s->draw_end)
			{
				ft_print_sprite_column(s, pars, params);
				s->start++;
			}
		}
		s->stripe++;
	}
}
