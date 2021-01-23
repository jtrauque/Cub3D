/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:53:13 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/23 21:18:38 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_extract_gun(t_data *text, t_params *params)
{
	char	*relative_path;

	relative_path = "./textures/jagpistol.xpm";
	text->img = mlx_xpm_file_to_image(params->mlx_ptr,
			relative_path, &text->img_width,
			&text->img_height);
	if (!text->img)
		return (ft_error("Wrong path to image or image missing\n"));
	text->data = (unsigned int *)mlx_get_data_addr(text->img,
			&text->bpp, &text->size_line,
			&text->endian);
	return (1);
}

void	ft_gun(t_params *params, t_pars *pars, t_data *gun)
{
	t_vecteur	map;
	t_mini		g;
	t_vecteur	c;
	int			color;

	ft_memset(&c, 0, sizeof(t_vecteur));
	map.x = pars->width / 2 - (pars->width / 4) / 2;
	map.y = pars->height - (pars->height / 3);
	while (c.y < pars->height / 3)
	{
		c.x = 0;
		g.y = c.y * gun->img_height / (pars->height / 3);
		while (c.x < pars->width / 4)
		{
			g.x = c.x * gun->img_width / (pars->width / 4);
			color = ft_get_px_from_image(gun, g.x, g.y);
			if (color != 0)
				ft_put_px_in_image(&params->data, c.x + map.x, c.y + map.y,
						color);
			c.x++;
		}
		c.y++;
	}
}
