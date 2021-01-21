/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:58:18 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/21 22:03:19 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_find(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_orient(t_pars *pars)
{
	char	*str;
	int		i;
	int		j;

	str = "NSWE";
	i = 0;
	j = 0;
	while (pars->map[j])
	{
		i = 0;
		while (pars->map[j][i])
		{
			if (ft_find(pars->map[j][i], str) == 1)
			{
				if (pars->map[j + 1][i] == ' ' || pars->map[j - 1][i] == ' '
						|| pars->map[j][i + 1] == ' '
						|| pars->map[j][i - 1] == ' ')
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int			ft_check_column(t_pars *pars, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	if (ft_check_orient(pars) == 0)
		return (0);
	while (i < params->map_w)
	{
		j = 0;
		while (j < params->map_h)
		{
			if (j < params->map_h - 1 && (pars->map[j][i] == '0' ||
					pars->map[j][i] == '2') && pars->map[j + 1][i] == ' ')
				return (0);
			if (j < params->map_h - 1 && pars->map[j][i] == ' ' &&
					(pars->map[j + 1][i] == '0' || pars->map[j + 1][i] == '2'))
				return (0);
			if (pars->map[j][i] == ' ')
				pars->map[j][i] = '1';
			j++;
		}
		i++;
	}
	return (ft_check_walls(pars, params));
}

int			ft_check_walls_column(t_pars *pars, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < params->map_h)
	{
		if (pars->map[i][0] != '1' && pars->map[i][0] != ' ')
			return (ft_error("map error - wall missing\n"));
		i++;
	}
	while (j < params->map_h)
	{
		if (pars->map[j][params->map_w - 1] != '1'
				&& pars->map[j][params->map_w - 1] != ' ')
			return (ft_error("map error - wall missing\n"));
		j++;
	}
	return (1);
}
