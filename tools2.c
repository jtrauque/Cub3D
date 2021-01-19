/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:25 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/19 20:12:23 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_release(t_pars *pars)
{
	pars->forward = 0;
	pars->backward = 0;
	pars->right = 0;
	pars->left = 0;
	pars->move_right = 0;
	pars->move_left = 0;
	printf("FOCUS OFF\n");
	return (0);
}
