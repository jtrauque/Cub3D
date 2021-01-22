/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:56:00 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/22 18:37:28 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		deal_key_release(int key, t_pars *pars)
{
	if (key == GO_FORWARD)
		pars->forward = 0;
	if (key == GO_BACKWARD)
		pars->backward = 0;
	if (key == TURN_RIGHT)
		pars->right = 0;
	if (key == TURN_LEFT)
		pars->left = 0;
	if (key == GO_RIGHT)
		pars->move_right = 0;
	if (key == GO_LEFT)
		pars->move_left = 0;
	return (0);
}

int		deal_key(int key, t_pars *pars)
{
	if (key == 65307)
		mlx_loop_end(pars->params->mlx_ptr);
	ft_move(key, pars);
	return (0);
}

void	ft_rotate(t_pars *pars, float n)
{
	float save_dir_x;
	float save_plane_x;
	float rotate_speed;
	float angle;

	rotate_speed = 0.1;
	angle = n * rotate_speed;
	save_dir_x = pars->dx;
	save_plane_x = pars->plane_x;
	pars->dx = pars->dx * cos(angle) - pars->dy * sin(angle);
	pars->dy = save_dir_x * sin(angle) + pars->dy * cos(angle);
	pars->plane_x = pars->plane_x * cos(angle) - pars->plane_y * sin(angle);
	pars->plane_y = save_plane_x * sin(angle) + pars->plane_y * cos(angle);
}

void	ft_move(int key, t_pars *pars)
{
	pars->speed = 0.1;
	if (key == GO_BACKWARD)
		pars->backward = 1;
	if (key == GO_FORWARD)
		pars->forward = 1;
	if (key == TURN_RIGHT)
		pars->right = 1;
	if (key == TURN_LEFT)
		pars->left = 1;
	if (key == GO_RIGHT)
		pars->move_right = 1;
	if (key == GO_LEFT)
		pars->move_left = 1;
}

void	ft_side_move(t_pars *pars)
{
	char c;

	if (pars->left == 1)
		ft_rotate(pars, -1.);
	if (pars->right == 1)
		ft_rotate(pars, 1.);
	if (pars->move_right == 1)
	{
		if ((c = pars->map[(int)pars->py][(int)(pars->px + pars->plane_x *
						pars->speed * 2)]) != '1' && c != '2' && c != '3')
			pars->px += pars->plane_x * pars->speed;
		if ((c = pars->map[(int)(pars->py + pars->plane_y * pars->speed * 2)]
					[(int)pars->px]) != '1' && c != '2' && c != '3')
			pars->py += pars->plane_y * pars->speed;
	}
	if (pars->move_left == 1)
	{
		if ((c = pars->map[(int)pars->py][(int)(pars->px - pars->plane_x *
						pars->speed * 2)]) != '1' && c != '2' && c != '3')
			pars->px -= pars->plane_x * pars->speed;
		if ((c = pars->map[(int)(pars->py - pars->plane_y * pars->speed * 2)]
					[(int)pars->px]) != '1' && c != '2' && c != '3')
			pars->py -= pars->plane_y * pars->speed;
	}
}
