/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:41:12 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/23 16:34:09 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_apply_text_on_wall(t_pars *pars, t_obs *obs, t_data *text)
{
	double column_x;

	if (obs->side == 2 || obs->side == 3)
		column_x = (double)pars->px + obs->true_dist * obs->raydir_x;
	else
		column_x = (double)pars->py + obs->true_dist * obs->raydir_y;
	column_x -= (int)(column_x);
	obs->text_x = (int)(column_x * (double)text->img_width);
	if ((obs->side == 0 || obs->side == 1) && obs->raydir_x > 0)
		obs->text_x = text->img_width - obs->text_x - 1;
	if ((obs->side == 2 || obs->side == 3) && obs->raydir_y < 0)
		obs->text_x = text->img_width - obs->text_x - 1;
}

void	ft_side_pick(t_pars *pars, t_obs *obs)
{
	if (obs->side == 1)
		obs->text = &pars->text[3];
	if (obs->side == 3)
		obs->text = &pars->text[0];
	if (obs->side == 0)
		obs->text = &pars->text[4];
	if (obs->side == 2)
		obs->text = &pars->text[1];
	ft_apply_text_on_wall(pars, obs, obs->text);
}

void	ft_background(t_pars *pars, t_params *params)
{
	int		middle_screen;
	int		y2;
	float	f;

	middle_screen = pars->height / 2;
	y2 = 0;
	f = 0.0;
	while (f < pars->width)
	{
		y2 = 0;
		while (y2 <= pars->height / 2)
		{
			ft_put_px_in_image(&params->data, f, middle_screen + y2,
					pars->color_f);
			ft_put_px_in_image(&params->data, f, middle_screen - y2,
					pars->color_c);
			y2++;
		}
		f += 1;
	}
}

void	ft_print_column(t_pars *pars, t_obs *obs, t_params *params)
{
	float		square_y;
	int			color;

	ft_distance_init(obs, pars);
	ft_detect_obs(pars, obs);
	ft_distance_init(obs, pars);
	obs->line = obs->draw_start;
	ft_side_pick(pars, obs);
	if (obs->heigth_column_pj > pars->height)
		square_y = ((float)(obs->heigth_column_pj - pars->height)) / 2. *
			(64. / obs->heigth_column_pj);
	else
		square_y = 0;
	while (obs->line < obs->draw_end)
	{
		color = ft_get_px_from_image(obs->text, obs->text_x, (int)square_y);
		square_y += 64. / obs->heigth_column_pj;
		ft_put_px_in_image(&params->data, obs->pix, obs->line, color);
		obs->line++;
	}
}

void	ft_look_at(t_pars *pars, t_params *params)
{
	t_obs		obs;
	t_sprite	sprite;

	obs.pix = 0;
	obs.line = 0;
	if (!(pars->buffer = malloc(sizeof(double) * pars->width + 1)))
		return ;
	ft_background(pars, params);
	while (obs.pix < pars->width)
	{
		ft_print_column(pars, &obs, params);
		obs.pix++;
	}
	ft_is_a_sprite(pars, &sprite);
	ft_mini_map(pars, params);
	ft_gun(params, pars, &pars->gun);
	if (pars->save != 1)
		mlx_put_image_to_window(params->mlx_ptr, params->win_ptr,
				params->data.img, 0, 0);
	free(pars->buffer);
}
