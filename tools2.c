/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:25 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/20 17:10:54 by jtrauque         ###   ########.fr       */
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

void		ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int			ft_check_str(char *str)
{
	int i;
	int n;
	int len;

	i = 0;
	n = 0;
	len = ft_strlen(str) - 1;
	i += ft_space(str);
	if (i == -1 || ft_isdigit(str[i]) == 0)
		return (-1);
	while (i < len && ft_isdigit(str[i]) != 0)
		i++;
	if (i < len && (n = ft_space(str + i)) == 0)
		return (-1);
	if (n > 0 && i + n < len)
		return (-1);
	return (1);
}
