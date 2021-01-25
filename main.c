/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:38:44 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/24 19:09:51 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_ext(char *argv)
{
	char *tmp;

	tmp = ft_strchr(argv, '.');
	if (!tmp)
		return (ft_error("Wrong extension - please use a .cub\n"));
	if (ft_strlen(tmp) != ft_strlen(".cub"))
		return (ft_error("Wrong extension - please use a .cub\n"));
	if (ft_strncmp(".cub", tmp, 4) != 0)
		return (ft_error("Wrong extension - please use a .cub\n"));
	return (1);
}

static int	ft_check_arg(int argc, char **argv, t_pars *pars)
{
	ft_memset(pars, 0, sizeof(t_pars));
	if (ft_check_ext(argv[1]) == 0)
		return (0);
	if (argc == 3)
	{
		if (ft_save_bmp(argv[2], pars) == 0)
			return (0);
	}
	return (1);
}

int			ft_window_put(t_params *params, t_pars *pars)
{
	params->data.img = mlx_new_image(params->mlx_ptr, pars->width,
			pars->height);
	params->data.data = (unsigned int *)mlx_get_data_addr(params->data.img,
			&params->data.bpp, &params->data.size_line, &params->data.endian);
	ft_manage_mlx(params, pars);
	if (pars->save != 1)
		mlx_loop(params->mlx_ptr);
	else
		ft_create_bmp(pars);
	ft_manage_mlx_destroy(params, pars);
	return (1);
}

int			main(int argc, char **argv)
{
	t_pars		pars;
	t_params	params;
	int			fd;

	if (!argv[1])
		return (ft_error("No arguments\n"));
	if (argc > 3)
		return (ft_error("To much arguments\n"));
	ft_memset(&params, 0, sizeof(t_params));
	if (ft_check_arg(argc, argv, &pars) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("No arguments valid\n"));
	params.mlx_ptr = mlx_init();
	pars.params = &params;
	if (ft_parsing(fd, &pars, &params) == 0 || !ft_global_map_check(&pars,
				&params) || ft_location_player(&pars) == 0
			|| ft_extract_gun(&pars.gun, &params) == 0)
		return (ft_free(&params, &pars));
	if (pars.save != 1)
		params.win_ptr = mlx_new_window(params.mlx_ptr, pars.width, pars.height,
				"Cub3D");
	ft_window_put(&params, &pars);
	return (0);
}
