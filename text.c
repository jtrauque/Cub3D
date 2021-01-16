/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:28:56 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 19:20:10 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_text_n(t_params *params, char *elements, t_pars *pars)
{
	char	*relative_path;
	int		i;

	i = 1;
	if (pars->text_n.img)
		return (ft_error("texture already existing\n"));
	if (elements[i] == 'O' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		i += 1;
		i += ft_space(elements + i);
		elements = ft_path(elements);
		relative_path = elements + i ;
		pars->text_n.img = mlx_xpm_file_to_image(params->mlx_ptr,
				relative_path, &pars->text_n.img_width,
				&pars->text_n.img_height);
		pars->text_n.data = (unsigned int *)mlx_get_data_addr(pars->text_n.img,
				&pars->text_n.bpp, &pars->text_n.size_line,
				&pars->text_n.endian);
	}
	else
		return (ft_error("error texture\n"));
	if (!pars->text_n.img)
		return (ft_error("texture not there\n"));
	return (1);
}

int		ft_text_sprite(t_params *params, char *elements, t_pars *pars)
{
	char	*relative_path;
	int		i;

	i = 1;
	pars->count += 1;
	if (pars->text_sprite.img)
		return (ft_error("texture already existing\n"));
	i += 1;
	i += ft_space(elements + i);
	elements = ft_path(elements);
	relative_path = elements + i;
	pars->text_sprite.img = mlx_xpm_file_to_image(params->mlx_ptr,
			relative_path, &pars->text_sprite.img_width,
			&pars->text_sprite.img_height);
	pars->text_sprite.data = (unsigned int *)mlx_get_data_addr(
			pars->text_sprite.img, &pars->text_sprite.bpp,
			&pars->text_sprite.size_line,
			&pars->text_sprite.endian);
	return (1);
}

int		ft_text_s(t_params *params, char *elements, t_pars *pars)
{
	char	*relative_path;
	int		i;

	i = 1;
	if (elements[i] == ' ')
		return (ft_text_sprite(params, elements, pars));
	else if (pars->text_s.img)
		return (ft_error("texture already existing\n"));
	else if (elements[i] == 'O' && elements[i + 1] == ' ')
	{
		i += 1;
		pars->count += 1;
		i += ft_space(elements + i);
		elements = ft_path(elements);
		relative_path = elements + i;
		pars->text_s.img = mlx_xpm_file_to_image(params->mlx_ptr,
				relative_path, &pars->text_s.img_width,
				&pars->text_s.img_height);
		pars->text_s.data = (unsigned int *)mlx_get_data_addr(pars->text_s.img,
				&pars->text_s.bpp, &pars->text_s.size_line,
				&pars->text_s.endian);
	}
	else
		return (ft_error("error texture\n"));
	return (1);
}

int		ft_text_w(t_params *params, char *elements, t_pars *pars)
{
	char	*relative_path;
	int		i;

	i = 1;
	if (pars->text_w.img)
		return (ft_error("texture already existing\n"));
	if (elements[i] == 'E' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		i += 1;
		i += ft_space(elements + i);
		elements = ft_path(elements);
		relative_path = elements + i;
		pars->text_w.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path,
				&pars->text_w.img_width, &pars->text_w.img_height);
		pars->text_w.data = (unsigned int *)mlx_get_data_addr(pars->text_w.img,
				&pars->text_w.bpp, &pars->text_w.size_line,
				&pars->text_w.endian);
	}
	else
		return (ft_error("error texture\n"));
	return (1);
}

int		ft_text_e(t_params *params, char *elements, t_pars *pars)
{
	char	*relative_path;
	int		i;

	i = 1;
	if (pars->text_e.img)
		return (ft_error("texture already existing\n"));
	if (elements[i] == 'A' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		i += 1;
		i += ft_space(elements + i);
		elements = ft_path(elements);
		relative_path = elements + i;
		pars->text_e.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path,
				&pars->text_e.img_width, &pars->text_e.img_height);
		pars->text_e.data = (unsigned int *)mlx_get_data_addr(pars->text_e.img,
				&pars->text_e.bpp, &pars->text_e.size_line,
				&pars->text_e.endian);
	}
	else
		return (ft_error("error texture\n"));
	return (1);
}
