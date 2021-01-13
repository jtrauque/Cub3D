#include "cub3d.h"

void ft_check_ext(char *argv)
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

int  main(int argc, char **argv)
{
  int fd;
  t_pars pars;
  t_params params;
  int i;

  ft_memset(&params, 0, sizeof(t_params));
  params.mlx_ptr = mlx_init();
  if (!argv[1])
    ft_error("No arguments\n");
  fd = open(argv[1], O_RDONLY);
  if (argc > 3)
    ft_error("To much arguments\n");
  if (fd < 0)
    ft_error("No arguments valid\n");
  ft_memset(&pars,0, sizeof(t_pars));
  if (argc == 3)
    ft_save_bmp(argv[2], &pars);
  if (argc == 2)
    ft_check_ext(argv[1]);
  ft_parsing(fd, &pars, &params);
  params.win_ptr = mlx_new_window(params.mlx_ptr, pars.width, pars.height, "Cub3D");
  params.data.img = mlx_new_image(params.mlx_ptr, pars.width, pars.height);
  params.data.data = (unsigned int *)mlx_get_data_addr(params.data.img, &params.data.bpp, &params.data.size_line, &params.data.endian);
  ft_global_map_check(&pars, &params);
  // // int k = 0;
  // while(pars.map[k]) {
  //   int t = 0;
  //   while (t < params.map_w) {
  //     printf("%s", pars.map[k][t] == '1' ? "\033[30m█" :"\033[31m█");
  //   ++t;
  //   }
  //   printf("\n\033[0m");
  //   ++k;
  //   // printf("%s\n", map[k++]);
  // }
  ft_location_player(&pars);
  ft_look_at(&pars, &params);
  printf("map.width = %d\n", params.map_w);
  printf("map.height = %d\n", params.map_h);
  printf("width = %d\n", pars.width);
  printf("height = %d\n", pars.height);
  printf("px = %f\n", pars.px);
  printf("py = %f\n", pars.py);
  printf("dx = %f\n", pars.dx);
  printf("dy = %f\n", pars.dy);
  printf("valeur a 27/10 = %c\n", pars.map[(int)pars.py][(int)(pars.px + pars.dx)]);
  printf("color floor = %d\n", pars.color_f);
  printf("color sky = %d\n", pars.color_c);
  pars.params = &params;
  ft_manage_mlx(&params, &pars);
  if (pars.save != 1)
    mlx_loop(params.mlx_ptr);
  else
    ft_create_bmp(&pars);
  ft_manage_mlx_destroy(&params, &pars);
  free(pars.map_tmp);
  i = 0;
  while (pars.map[i]) {
    free(pars.map[i]);
    i++;
  }
  free(pars.map);
  free(params.mlx_ptr);
  free(pars.sprite);
  return (0);
}

