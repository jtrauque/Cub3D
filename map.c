/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:54:15 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 17:39:07 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_find_orientation(char c, char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

char		*ft_map_valide(char *elements, t_pars *pars, t_params *params)
{
	int		i;
	char	*caracteres;
	char	*temp;

	caracteres = "012NSEW ";
	temp = elements;
	(void)pars;
	i = 0;
	if (temp[i] != '1' && temp[i] != ' ')
		return (NULL);
	while (temp[i])
	{
		if (temp[i] == '0' && temp[i + 1] == ' ')
			return (NULL);
		if (temp[i] == ' ' && temp[i + 1] == '0')
			return (NULL);
		if (ft_find_orientation(temp[i], caracteres) == 0)
			return (NULL);
		i++;
	}
	if (temp[i - 1] != '1')
		return (NULL);
	if (i > params->map_w)
		params->map_w = i;
	return (temp);
}

int			ft_map_save(t_params *params, char *elements, t_pars *pars)
{
	char *tmp;

	pars->count += 1;
	if ((tmp = ft_map_valide(elements, pars, params)) != NULL)
	{
		if (!(pars->map_tmp = ft_strnjoin(pars->map_tmp, tmp, ft_strlen(tmp))))
			return (0);
		if (!(pars->map_tmp = ft_strnjoin(pars->map_tmp, "\n", 1)))
			return (0);
	}
	else
		return (ft_error("map not valid\n"));
	return (1);
}

int			ft_check_walls(t_pars *pars, t_params *params)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (pars->map[0][i])
	{
		if (pars->map[0][i] != '1')
			return (ft_error("map error - wall missing\n"));
		i++;
	}
	while (pars->map[params->map_h - 1][j])
	{
		if (pars->map[params->map_h - 1][j] != '1')
			return (ft_error("map error - wall missing\n"));
		j++;
	}
	return (ft_check_walls_column(pars, params));
}

char		**ft_global_map_check(t_pars *pars, t_params *params)
{
	int		j;
	int		count;
	char	*obs;

	j = 0;
	count = 0;
	obs = "NSWE";
	if (!pars->map_tmp)
		return (ft_error_map("No Map ???\n"));
	while (obs[j])
	{
		if (ft_find_orientation(obs[j], pars->map_tmp) == 1)
			count++;
		if (ft_find_orientation(obs[j], pars->map_tmp) > 1)
			return (ft_error_map("map error\n"));
		j++;
	}
	if (count > 1 || count == 0)
		return (ft_error_map("map error - too much or no players\n"));
	pars->map = ft_split_one(pars->map_tmp, '\n', params);
	if (ft_check_walls(pars, params) == 0)
		return (NULL);
	return (pars->map);
}
