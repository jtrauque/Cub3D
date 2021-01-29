/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:17:34 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/29 20:17:22 by jtrauque         ###   ########.fr       */
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

void	ft_sort_sprite(t_pars *pars, t_vecteur *sprite, int nbr)
{
	int			i;
	int			first;
	int			second;
	t_vecteur	tmp;

	i = 0;
	while (i < nbr - 1)
	{
		first = ((pars->px - sprite[i].x) * (pars->px -
					sprite[i].x) + (pars->py - sprite[i].y) *
				(pars->py - sprite[i].y));
		second = ((pars->px - sprite[i + 1].x) * (pars->px -
					sprite[i + 1].x) + (pars->py - sprite[i + 1].y)
				* (pars->py - sprite[i + 1].y));
		if (first < second)
		{
			tmp = sprite[i];
			sprite[i] = sprite[i + 1];
			sprite[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_join_sprite_bonus(t_pars *pars)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(pars->all_sprite = malloc(sizeof(t_vecteur) * (pars->sprite_nbr +
						pars->sprite_bonus_nbr))))
		return ;
	while (i < pars->sprite_nbr)
	{
		pars->all_sprite[i] = pars->sprite[i];
		pars->all_sprite[i].text = 2;
		i++;
	}
	while (j < pars->sprite_bonus_nbr)
	{
		pars->all_sprite[i] = pars->sprite_bonus[j];
		pars->all_sprite[i].text = 5;
		i++;
		j++;
	}
}

void	ft_print_sprite_column(t_sprite *s, t_pars *pars, t_params *params,
		int i)
{
	int color;
	int n;

	n = s->start * pars->text[i].size_line - pars->height *
		(pars->text[i].size_line / 2) +
		s->heigth_column * (pars->text[i].size_line / 2);
	s->draw_y = ((n * pars->text[i].img_height) /
			s->heigth_column) / pars->text[i].size_line;
	color = ft_get_px_from_image(&pars->text[i], s->draw_x
			, s->draw_y);
	if (color != 0)
		ft_put_px_in_image(&params->data, s->stripe, s->start, color);
}

void	ft_sprite_loop(t_pars *pars, t_sprite *s, t_vecteur *sprite, int n)
{
	s->sprite_x = sprite[n].x - (pars->px - .5);
	s->sprite_y = sprite[n].y - (pars->py - .5);
	ft_sprite_init(pars, s);
	s->stripe = s->width_draw_start;
	while (s->stripe < s->width_draw_end)
	{
		s->draw_x = (int)(pars->text[sprite[n].text].size_line * (s->stripe -
					(-s->width_column / 2 + s->sprite_screen)) *
				pars->text[sprite[n].text].img_width / s->width_column) /
			pars->text[sprite[n].text].size_line;
		if (s->next_y > 0 && s->stripe > 0 && s->stripe < pars->width &&
				s->next_y < pars->buffer[s->stripe])
		{
			s->start = s->draw_start;
			while (s->start < s->draw_end)
			{
				ft_print_sprite_column(s, pars, pars->params, sprite[n].text);
				s->start++;
			}
		}
		s->stripe++;
	}
}
