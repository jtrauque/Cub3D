/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:38:44 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/14 22:25:08 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_ext(char *argv)
{
	char *tmp;

	tmp = ft_strchr(argv, '.');
	if (!tmp)
		ft_error("Wrong extension - please use a .cub\n");
	if (ft_strlen(tmp) != ft_strlen(".cub"))
		ft_error("Wrong extension - please use a .cub\n");
	if (ft_strncmp(".cub", tmp, 4) != 0)
		ft_error("Wrong extension - please use a .cub\n");
}
void	ft_check_arg(int argc, char **argv, int fd, t_pars *pars)
{
	if (argc > 3)
		ft_error("To much arguments\n");
	if (fd < 0)
		ft_error("No arguments valid\n");
	printf("1\n");
	ft_memset(&pars, 0, sizeof(t_pars));
	printf("2\n");
	if (argc == 3)
		ft_save_bmp(argv[2], pars);
	printf("3\n");
	if (argc == 2)
		ft_check_ext(argv[1]);
	printf("4-\n");
}

int		main(int argc, char **argv)
{
	t_pars		pars;
	t_params	params;
	int			fd;
	int			i;

	ft_memset(&params, 0, sizeof(t_params));
	params.mlx_ptr = mlx_init();
	if (!argv[1])
		ft_error("No arguments\n");
	fd = open(argv[1], O_RDONLY);
	printf("5-\n");
	ft_check_arg(argc, argv, fd, &pars);
	printf("6\n");
	ft_parsing(fd, &pars, &params);
	params.win_ptr = mlx_new_window(params.mlx_ptr, pars.width, pars.height, "Cub3D");
	params.data.img = mlx_new_image(params.mlx_ptr, pars.width, pars.height);
	params.data.data = (unsigned int *)mlx_get_data_addr(params.data.img, &params.data.bpp, &params.data.size_line, &params.data.endian);
	ft_global_map_check(&pars, &params);
	ft_location_player(&pars);
	ft_look_at(&pars, &params);
	pars.params = &params;
	ft_manage_mlx(&params, &pars);
	if (pars.save != 1)
		mlx_loop(params.mlx_ptr);
	else
		ft_create_bmp(&pars);
	ft_manage_mlx_destroy(&params, &pars);
	free(pars.map_tmp);
	i = 0;
	while (pars.map[i])
	{
		free(pars.map[i]);
		i++;
	}
	free(pars.map);
	free(params.mlx_ptr);
	free(pars.sprite);
	return (0);
}
