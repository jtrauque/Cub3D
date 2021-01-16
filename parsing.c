/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:04:46 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 19:01:23 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef int	(*t_fn_parsing_t)(t_params *params, char *str, t_pars *p);
t_fn_parsing_t g_parsing[8] = {ft_resolution, ft_text_n, ft_text_s, ft_text_w,
	ft_text_e, ft_color, ft_color, ft_map_save};

int		ft_identify_type(char c)
{
	char	*type;
	int		i;

	type = "RNSWEFC1";
	i = 0;
	while (type[i])
	{
		if (type[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_parsing(int fd, t_pars *pars, t_params *params)
{
	char	*elements;
	int		i;
	int		n;
	int		r;

	r = 1;
	while (r == 1 && (get_next_line(fd, &elements)) > 0)
	{
		if ((n = ft_space(elements)) == -1)
		{
			free(elements);
			if (pars->count > 8)
				return (ft_error("Empty lines in the map\n"));
			continue;
		}
		if ((i = ft_identify_type(elements[n])) == 7 && pars->count >= 8)
			r = g_parsing[i](params, elements, pars);
		else if (i != -1 && i != 7)
			r = g_parsing[i](params, elements + n, pars);
		free(elements);
		if (!(i == 7 && pars->count >= 8) && !(i != 7 && i != -1))
			return (ft_error("error elements\n"));
	}
	return (r);
}

int		ft_resolution(t_params *params, char *elements, t_pars *pars)
{
	int i;
	int width_max;
	int height_max;

	i = 1;
	pars->count += 1;
	i += ft_space(elements + i);
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
		pars->width = pars->width * 10 + (elements[i++] - '0');
	i += ft_space(elements + i);
	while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
		pars->height = pars->height * 10 + (elements[i++] - '0');
	mlx_get_screen_size(params->mlx_ptr, &width_max, &height_max);
	if (pars->width > width_max)
		pars->width = width_max;
	if (pars->height > height_max)
		pars->height = height_max;
	if (pars->width == 0 || pars->height == 0)
		return (ft_error("error resolution\n"));
	return (1);
}
