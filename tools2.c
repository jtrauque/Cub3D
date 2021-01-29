/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:25 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/29 20:14:46 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_release(t_pars *pars)
{
	pars->forward = 0;
	pars->backward = 0;
	pars->right = 0;
	pars->left = 0;
	pars->move_right = 0;
	pars->move_left = 0;
	return (0);
}

void		ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int			ft_check_str(char *str)
{
	int i;
	int n;
	int len;

	i = 0;
	n = 0;
	len = ft_strlen(str) - 1;
	i += ft_space(str);
	if (i == -1 || ft_isdigit(str[i]) == 0)
		return (-1);
	while (i < len && ft_isdigit(str[i]) != 0)
		i++;
	if (i < len && (n = ft_space(str + i)) == 0)
		return (-1);
	if (n > 0 && str[i + n])
		return (-1);
	return (1);
}

int			ft_check_commas(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void		ft_is_a_sprite(t_pars *pars, t_sprite *sprite)
{
	if (pars->is_a_sprite_b != 0)
	{
		pars->n_spriteb = -1;
		ft_sort_sprite(pars, pars->all_sprite, (pars->sprite_nbr +
					pars->sprite_bonus_nbr));
		while (++pars->n_spriteb < (pars->sprite_bonus_nbr + pars->sprite_nbr))
			ft_sprite_loop(pars, sprite, pars->all_sprite, pars->n_spriteb);
	}
	else if (pars->is_a_sprite != 0 && pars->is_a_sprite_b == 0)
	{
		sprite->n = -1;
		ft_sort_sprite(pars, pars->sprite, pars->sprite_nbr);
		while (++sprite->n < pars->sprite_nbr)
			ft_sprite_loop(pars, sprite, pars->sprite, sprite->n);
	}
}
