/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:28:56 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/29 20:16:07 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_text(t_params *params, char *elements, t_pars *pars)
{
	int			i;
	static char	*str[] = {"NO ", "SO ", "S ", "WE ", "EA ", "SB "};

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(str[i], elements, ft_strlen(str[i])) == 0)
			break ;
		i++;
	}
	if (pars->text[i].img)
		return (ft_error("texture already existing\n"));
	else if (ft_extract_text(elements, &pars->text[i], params) == 0)
		return (0);
	if (!pars->text[i].img)
		return (ft_error("texture not there\n"));
	if (i != 5)
		pars->count += 1;
	return (1);
}

static int	ft_check_ext_img(char *str)
{
	char *tmp;
	int  i;

	i = 0;
	tmp = ft_strchr(str + 1, '.');
	if (!tmp)
		return (ft_error("Please check your texture path\n"));
	if (ft_strlen(tmp) < ft_strlen(".xpm"))
		return (ft_error("Wrong extension - please use a .xpm\n"));
	if (ft_strncmp(".xpm", tmp, 4) != 0)
		return (ft_error("Wrong extension - please use a .xpm\n"));
	if (tmp[4] && (i = ft_space(tmp + 4)) == 0)  
		return (ft_error("too much arguments - please use only a .xpm\n"));
	if (i > 0 && 4 + i < ft_strlen(tmp))  
		return (ft_error("too much arguments - please use only a .xpm\n"));
	return (1);
}

char		*ft_path(char *elements)
{
	int j;

	j = ft_strlen(elements);
	while (elements[j - 1] == ' ' || elements[j - 1] == '\t')
		j--;
	elements[j] = '\0';
	return (elements);
}

int			ft_extract_text(char *elements, t_data *text, t_params *params)
{
	char	*relative_path;
	int		i;

	i = 2;
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
