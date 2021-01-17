/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:36:07 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/17 19:19:11 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_space_and_plus(char *elements)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (elements[i])
	{
		if (elements[i] == ' ')
			i++;
		else if (elements[i] == ',')
		{
			if (count < 2)
				count++;
			else
				ft_error("too much ,\n");
			i++;
		}
		else
			return (i);
	}
	return (-1);
}

int		ft_space(char *elements)
{
	int i;

	i = 0;
	while (elements[i])
	{
		if (elements[i] == ' ')
			i++;
		else
			return (i);
	}
	return (-1);
}

int		ft_error(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	return (0);
}

void	*ft_error_map(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	return (NULL);
}

int		ft_free(t_params *params, t_pars *pars)
{
	int i;

	i = 0;
	if (params->data.img)
		mlx_destroy_image(params->mlx_ptr, params->data.img);
	if (pars->text_n->img)
		mlx_destroy_image(params->mlx_ptr, pars->text_n->img);
	if (pars->text_s->img)
		mlx_destroy_image(params->mlx_ptr, pars->text_s->img);
	if (pars->text_e->img)
		mlx_destroy_image(params->mlx_ptr, pars->text_e->img);
	if (pars->text_w->img)
		mlx_destroy_image(params->mlx_ptr, pars->text_w->img);
	if (pars->text_sprite->img)
		mlx_destroy_image(params->mlx_ptr, pars->text_sprite->img);
	if (pars->map)
		while (pars->map[i])
			free(pars->map[i++]);
	free(pars->map);
	free(pars->map_tmp);
	free(params->mlx_ptr);
	return (0);
}
