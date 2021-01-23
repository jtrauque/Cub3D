/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:30:50 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/23 22:14:50 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_arg_nbr(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_rgb(char *elements)
{
	char	**str;
	t_color	color;

	ft_memset(&color, 0, sizeof(t_color));
	str = ft_split(elements, ',');
	if (ft_arg_nbr(str) != 3 || ft_check_str(str[0]) != 1
			|| ft_check_str(str[1]) != 1 || ft_check_str(str[2]) != 1)
	{
		ft_free_tab(str);
		return (-1);
	}
	color.r = ft_atoi(str[0]);
	color.g = ft_atoi(str[1]);
	color.b = ft_atoi(str[2]);
	if (color.r > 255 || color.r < 0 || color.g > 255 || color.g < 0 ||
			color.b > 255 || color.b < 0)
	{
		ft_free_tab(str);
		return (-1);
	}
	ft_free_tab(str);
	return (65536 * color.r + 256 * color.g + color.b);
}

int			ft_color(t_params *params, char *elements, t_pars *pars)
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

void		ft_put_px_in_image(t_data *data, int x, int y, int color)
{
	int pos;

	pos = (y * data->size_line + x * data->bpp / 8) / sizeof(int);
	data->data[pos] = color;
}

int			ft_get_px_from_image(t_data *data, unsigned int x, unsigned int y)
{
	int pos;

	if (y > (unsigned int)data->img_height || x > (unsigned int)data->img_width)
		return (0);
	pos = (y * data->size_line + x * data->bpp / 8) / sizeof(int);
	return (data->data[pos]);
}
