/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:30:50 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/14 21:12:06 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_rgb(char *elements)
{
	int		i;
	t_color	color;

	i = 0;
	ft_memset(&color, 0, sizeof(t_color));
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
	{
		color.R = color.R * 10 + (elements[i] - '0');
		i++;
	}
	i++;
	i += ft_space(elements + i);
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
	{
		color.G = color.G * 10 + (elements[i] - '0');
		i++;
	}
	i++;
	i += ft_space(elements + i);
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
	{
		color.B = color.B * 10 + (elements[i] - '0');
		i++;
	}
	return (65536 * color.R + 256 * color.G + color.B);
}

void	ft_color(t_params *params, char *elements, t_pars *pars)
{
	int i;

	i = 1;
	pars->count += 1;
	(void)params;
	if (elements[0] == 'F' && elements[1] == ' ')
	{
		i += ft_space(elements + i);
		pars->color_f = ft_rgb(elements + i);
	}
	else if (elements[0] == 'C' && elements[1] == ' ')
	{
		i += ft_space(elements + i);
		pars->color_c = ft_rgb(elements + i);
	}
	else
		ft_error("error color\n");
}

void	ft_put_px_in_image(t_data *data, int x, int y, int color)
{
	int pos;

	pos = (y * data->size_line + x * data->bpp / 8) / sizeof(int);
	data->data[pos] = color;
}

int		ft_get_px_from_image(t_data *data, int x, int y)
{
	int pos;

	pos = (y * data->size_line + x * data->bpp / 8) / sizeof(int);
	return (data->data[pos]);
}
