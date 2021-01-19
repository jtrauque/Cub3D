/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:30:50 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/19 13:57:12 by jtrauque         ###   ########.fr       */
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
		color.r = color.r * 10 + (elements[i++] - '0');
	i++;
	if (ft_space_and_plus(elements + i) == -1)
		return (-1);
	i += ft_space_and_plus(elements + i);
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
		color.g = color.g * 10 + (elements[i++] - '0');
	i++;
	if (ft_space_and_plus(elements + i) == -1)
		return (-1);
	i += ft_space_and_plus(elements + i);
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
		color.b = color.b * 10 + (elements[i++] - '0');
	if (color.r > 255 || color.r < 0 || color.g > 255 || color.g < 0 ||
			color.b > 255 || color.b < 0 || ft_space(elements + i) != -1)
		return (-1);
	return (65536 * color.r + 256 * color.g + color.b);
}

int		ft_color(t_params *params, char *elements, t_pars *pars)
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
		return (ft_error("error color\n"));
	if (pars->color_f == -1 || pars->color_c == -1)
		return (ft_error("error rgb\n"));
	return (1);
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
