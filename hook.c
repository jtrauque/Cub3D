/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:52:39 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/23 22:25:56 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cross_exit(t_pars *pars)
{
	mlx_loop_end(pars->params->mlx_ptr);
	return (0);
}

int		minimize_win(t_params *params)
{
	mlx_put_image_to_window(params->mlx_ptr, params->win_ptr,
				params->data.img, 0, 0);
	return (0);
}

int		game_loop(t_pars *pars)
{
	char c;

	if (pars->forward == 1)
	{
		if ((c = pars->map[(int)pars->py][(int)(pars->px + pars->dx *
						pars->speed * 2)]) != '1' && c != '2' && c != '3')
			pars->px += pars->dx * pars->speed;
		if ((c = pars->map[(int)(pars->py + pars->dy * pars->speed * 2)]
					[(int)pars->px]) != '1' && c != '2' && c != '3')
			pars->py += pars->dy * pars->speed;
	}
	if (pars->backward == 1)
	{
		if ((c = pars->map[(int)pars->py][(int)(pars->px - pars->dx *
						pars->speed * 2)]) != '1' && c != '2' && c != '3')
			pars->px -= pars->dx * pars->speed;
		if ((c = pars->map[(int)(pars->py - pars->dy * pars->speed * 2)]
					[(int)pars->px]) != '1' && c != '2' && c != '3')
			pars->py -= pars->dy * pars->speed;
	}
	ft_side_move(pars);
	if (pars->forward == 1 || pars->backward == 1 || pars->right == 1 ||
			pars->left == 1 || pars->move_left == 1 || pars->move_right == 1)
		ft_look_at(pars, pars->params);
	return (0);
}

void	ft_manage_mlx(t_params *params, t_pars *pars)
{
	ft_look_at(pars, params);
	if (pars->save != 1)
	{
		mlx_hook(params->win_ptr, 2, 1 << 0, deal_key, pars);
		mlx_hook(params->win_ptr, 3, 1L << 1, deal_key_release, pars);
		mlx_hook(params->win_ptr, 12, 1L << 15, minimize_win, params);
		mlx_hook(params->win_ptr, 33, 1L << 0, cross_exit, pars);
		mlx_do_key_autorepeatoff(params->mlx_ptr);
		mlx_loop_hook(params->mlx_ptr, game_loop, pars);
		mlx_hook(params->win_ptr, 10, 1L << 21, ft_release, pars);
	}
}

void	ft_manage_mlx_destroy(t_params *params, t_pars *pars)
{
	if (pars->save != 1)
	{
		mlx_do_key_autorepeaton(params->mlx_ptr);
		mlx_do_sync(params->mlx_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	}
	ft_free(params, pars);
}
