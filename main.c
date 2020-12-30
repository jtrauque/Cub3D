#include "cub3d.h"

typedef void (*t_fn_parsing_t)(t_params *params, char *str,t_pars *p);
t_fn_parsing_t g_parsing[8] = {ft_resolution, ft_text_n, ft_text_s, ft_text_w, ft_text_e, ft_color, ft_color, ft_map_save};

int  main(int argc, char ** argv)
{
  int fd;
  char *elements;
  t_pars pars;
  t_params params;
  int i;
  int n;
  int len;
  // char **map;

  ft_memset(&params, 0, sizeof(t_params));
  params.mlx_ptr = mlx_init();
  elements = NULL;
  n = 0;
  fd = open(argv[1], O_RDONLY);
  if (argc != 2)
    return (1);
  if (fd < 0)
    return (1);
  ft_memset(&pars,0, sizeof(t_pars));
  while ((len = get_next_line(fd, &elements)) > 0)
  {
  //  printf("len = %d\n", len);
    if ((n = ft_space(elements)) == -1)
    {
      free(elements);
      continue;
    }
    i = ft_identify_type(elements[n]);
 //   printf("elements[%d] = %c\n", n, elements[n]);
    // printf("i = %d\n", i);
    if (i == 7)
      g_parsing[i](&params,elements, &pars);
    else if (i != - 1)
      g_parsing[i](&params,elements + n, &pars);
    else
      ft_error("error elements\n");
    free(elements);
  }
  params.win_ptr = mlx_new_window(params.mlx_ptr, pars.width, pars.height, "Cub3D");
  params.data.img = mlx_new_image(params.mlx_ptr, pars.width, pars.height);
  params.data.data = (unsigned int *)mlx_get_data_addr(params.data.img, &params.data.bpp, &params.data.size_line, &params.data.endian);
  // params.img = mlx_new_image();
  // printf("map.width main = %d\n", params.map_w);
  pars.map = ft_global_map_check(&pars, &params);
  int k = 0;
  while(pars.map[k]) {
    int t = 0;
    while (t < params.map_w) {
      printf("%s", pars.map[k][t] == '1' ? "\033[30m█" :"\033[31m█");
    ++t;
    }
    printf("\n\033[0m");
    ++k;
    // printf("%s\n", map[k++]);
  }
  ft_location_player(&pars, pars.map);
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
 // printf("map = \n%s\n", pars.map);
  pars.params = &params;
  mlx_key_hook(params.win_ptr, deal_key, &pars);
  mlx_loop(params.mlx_ptr);
  free(pars.map_tmp);
  free(pars.map);
  return (0);
}

