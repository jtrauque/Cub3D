/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:36:07 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/29 20:26:50 by jtrauque         ###   ########.fr       */
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
		if (elements[i] == ' ' || elements[i] == '\t')
			i++;
		else if (elements[i] == ',')
		{
			if (count < 2)
				count++;
			else
				ft_error("too much ,\n");
			i++;
		}
		else if (!(elements[i] >= '0' && elements[i] <= '9'))
			return (-1);
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
		if (elements[i] == ' ' || elements[i] == '\t')
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
	int j;

	i = 0;
	j = 0;
	if (params->data.img)
		mlx_destroy_image(params->mlx_ptr, params->data.img);
	if (pars->gun.img)
		mlx_destroy_image(params->mlx_ptr, pars->gun.img);
	while (j < 6)
	{
		if (pars->text[j].img)
			mlx_destroy_image(params->mlx_ptr, pars->text[j].img);
		j++;
	}
	if (pars->map)
		while (pars->map[i])
			free(pars->map[i++]);
	free(pars->map);
	free(pars->map_tmp);
	mlx_destroy_display(params->mlx_ptr);
	free(params->mlx_ptr);
	free(pars->sprite);
	free(pars->sprite_bonus);
	free(pars->all_sprite);
	return (0);
}
