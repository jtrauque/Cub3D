/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:28:56 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/17 20:57:55 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_text_n(t_params *params, char *elements, t_pars *pars)
{
	int		i;

	i = 1;
	if (pars->text_n->img)
		return (ft_error("texture already existing\n"));
	if (elements[i] == 'O' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		if (ft_extract_text(elements, pars->text_n, params, i) == 0)
			return (0);
	}
	else
		return (ft_error("error texture\n"));
	if (!pars->text_n->img)
		return (ft_error("texture not there\n"));
	return (1);
}

int		ft_text_sprite(t_params *params, char *elements, t_pars *pars)
{
	int		i;

	i = 1;
	if (pars->text_sprite->img)
		return (ft_error("texture already existing\n"));
	pars->count += 1;
	if (ft_extract_text(elements, pars->text_n, params, i) == 0)
		return (0);
	if (!pars->text_sprite->img)
		return (ft_error("texture not there\n"));
	return (1);
}

int		ft_text_s(t_params *params, char *elements, t_pars *pars)
{
	int		i;

	i = 1;
	if (elements[i] == ' ')
		return (ft_text_sprite(params, elements, pars));
	else if (pars->text_s->img)
		return (ft_error("texture already existing\n"));
	else if (elements[i] == 'O' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		if (ft_extract_text(elements, pars->text_n, params, i) == 0)
			return (0);
	}
	else
		return (ft_error("error texture\n"));
	if (!pars->text_s->img)
		return (ft_error("texture not there\n"));
	return (1);
}

int		ft_text_w(t_params *params, char *elements, t_pars *pars)
{
	int		i;

	i = 1;
	if (pars->text_w->img)
		return (ft_error("texture already existing\n"));
	if (elements[i] == 'E' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		if (ft_extract_text(elements, pars->text_n, params, i) == 0)
			return (0);
	}
	else
		return (ft_error("error texture\n"));
	if (!pars->text_w->img)
		return (ft_error("texture not there\n"));
	return (1);
}

int		ft_text_e(t_params *params, char *elements, t_pars *pars)
{
	int		i;

	i = 1;
	if (pars->text_e->img)
		return (ft_error("texture already existing\n"));
	if (elements[i] == 'A' && elements[i + 1] == ' ')
	{
		pars->count += 1;
		if (ft_extract_text(elements, pars->text_n, params, i) == 0)
			return (0);
	}
	else
		return (ft_error("error texture\n"));
	if (!pars->text_e->img)
		return (ft_error("texture not there\n"));
	return (1);
}
