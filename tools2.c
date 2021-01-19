/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:25 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/19 17:38:38 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_path(char *elements)
{
	int j;

	j = ft_strlen(elements);
	while (elements[j - 1] == ' ')
		j--;
	elements[j] = '\0';
	return (elements);
}

static int	ft_check_ext_img(char *str)
{
	char *tmp;

	tmp = ft_strchr(str + 1, '.');
	if (!tmp)
		return (ft_error("Wrong extension - please use a .xpm\n"));
	if (ft_strlen(tmp) != ft_strlen(".xpm"))
		return (ft_error("Wrong extension - please use a .xpm\n"));
	if (ft_strncmp(".xpm", tmp, 4) != 0)
		return (ft_error("Wrong extension - please use a .xpm\n"));
	return (1);
}

int			ft_extract_text(char *elements, t_data *text, t_params *params,
		int i)
{
	char	*relative_path;

	i += 1;
	i += ft_space(elements + i);
	elements = ft_path(elements);
	relative_path = elements + i;
	if (ft_check_ext_img(relative_path) == 0)
		return (0);
	text->img = mlx_xpm_file_to_image(params->mlx_ptr,
			relative_path, &text->img_width,
			&text->img_height);
	if (!text->img)
		return (ft_error("Wrong path to image or image missing\n"));
	text->data = (unsigned int *)mlx_get_data_addr(text->img,
			&text->bpp, &text->size_line,
			&text->endian);
	return (1);
}

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
