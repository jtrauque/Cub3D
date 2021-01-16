/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:52:39 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 15:58:02 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cross_exit(t_pars *pars)
{
	mlx_loop_end(pars->params->mlx_ptr);
	return (0);
}

int		minimize_win(t_pars *pars)
{
	ft_look_at(pars, pars->params);
	return (0);
}

int		game_loop(t_pars *pars)
{
	char c;

	if (pars->forward == 1)
	{
		if ((c = pars->map[(int)pars->py][(int)(pars->px + pars->dx *
						pars->speed)]) != '1' && c != '2')
			pars->px += pars->dx * pars->speed;
		if ((c = pars->map[(int)(pars->py + pars->dy * pars->speed)]
					[(int)pars->px]) != '1' && c != '2')
			pars->py += pars->dy * pars->speed;
	}
	if (pars->backward == 1)
	{
		if ((c = pars->map[(int)pars->py][(int)(pars->px - pars->dx *
						pars->speed)]) != '1' && c != '2')
			pars->px -= pars->dx * pars->speed;
		if ((c = pars->map[(int)(pars->py - pars->dy * pars->speed)]
					[(int)pars->px]) != '1' && c != '2')
			pars->py -= pars->dy * pars->speed;
	}
	ft_side_move(pars);
	ft_look_at(pars, pars->params);
	return (0);
}

int		ft_manage_mlx(t_params *params, t_pars *pars)
{
	if (!ft_global_map_check(pars, params))
		return (ft_error("map error\n"));
	if(ft_location_player(pars) == 0)
		return (ft_error("player error\n"));
	ft_look_at(pars, params);
	if (pars->save != 1)
	{
		mlx_hook(params->win_ptr, 2, 1 << 0, deal_key, pars);
		mlx_hook(params->win_ptr, 3, 1L << 1, deal_key_release, pars);
		mlx_hook(params->win_ptr, 12, 1L << 15, minimize_win, pars);
		mlx_hook(params->win_ptr, 33, 1L << 0, cross_exit, pars);
		mlx_do_key_autorepeatoff(params->mlx_ptr);
		mlx_loop_hook(params->mlx_ptr, game_loop, pars);
	}
	return (1);
}

void	ft_manage_mlx_destroy(t_params *params, t_pars *pars)
{
	int i;

	i = 0;
	mlx_destroy_image(params->mlx_ptr, params->data.img);
	mlx_destroy_image(params->mlx_ptr, pars->text_n.img);
	mlx_destroy_image(params->mlx_ptr, pars->text_s.img);
	mlx_destroy_image(params->mlx_ptr, pars->text_e.img);
	mlx_destroy_image(params->mlx_ptr, pars->text_w.img);
	mlx_destroy_image(params->mlx_ptr, pars->text_sprite.img);
	if (pars->save != 1)
	{
		mlx_do_key_autorepeaton(params->mlx_ptr);
		mlx_do_sync(params->mlx_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
	}
	free(pars->map_tmp);
	while (pars->map[i])
	{
		free(pars->map[i]);
		i++;
	}
	free(pars->map);
	free(params->mlx_ptr);
	free(pars->sprite);
}

int		ft_free(t_params *params, t_pars *pars)
{	
	if (params->data.img)
		mlx_destroy_image(params->mlx_ptr, params->data.img);
	if (pars->text_n.img)
		mlx_destroy_image(params->mlx_ptr, pars->text_n.img);
	if (pars->text_s.img)
		mlx_destroy_image(params->mlx_ptr, pars->text_s.img);
	if (pars->text_e.img)
		mlx_destroy_image(params->mlx_ptr, pars->text_e.img);
	if (pars->text_w.img)
		mlx_destroy_image(params->mlx_ptr, pars->text_w.img);
	if (pars->text_sprite.img)
		mlx_destroy_image(params->mlx_ptr, pars->text_sprite.img);
	free(pars->map_tmp);
	free(params->mlx_ptr);
	return (0);
}
