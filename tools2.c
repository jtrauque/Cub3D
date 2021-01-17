/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:19:25 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/17 13:19:48 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_path(char *elements)
{
	int j;

	j = ft_strlen(elements);
	while (elements[j - 1] == ' ')
		j--;
	elements[j] = '\0';
	return (elements);
}

void	ft_extract_text(char *elements, t_data *text, t_params *params, int i)
{
	char	*relative_path;

	i += 1;
	i += ft_space(elements + i);
	elements = ft_path(elements);
	relative_path = elements + i;
	text->img = mlx_xpm_file_to_image(params->mlx_ptr,
			relative_path, &text->img_width,
			&text->img_height);
	text->data = (unsigned int *)mlx_get_data_addr(text->img,
			&text->bpp, &text->size_line,
			&text->endian);
}
