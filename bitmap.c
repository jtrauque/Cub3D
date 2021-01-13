#include "cub3d.h"

void  ft_create_header(t_pars *pars, t_info_header *info, t_file_header *file)
{
  ft_memset(info, 0, sizeof(t_info_header));
  ft_memset(file, 0, sizeof(t_file_header));
  file->signature[0] = 'B';
  file->signature[1] = 'M';
  file->sizeinbytes = sizeof(t_file_header) + sizeof(t_info_header) 
  + pars->height * pars->width * 3;
  file->sizeinbytes = sizeof(t_file_header) + sizeof(t_info_header);
  info->header_size = sizeof(t_info_header);
  info->width = pars->width;
  info->height = pars->height;
  info->nmb_color_planes = 1;
  info->color_depth = 24;
}

void  ft_generate_image(t_pars *pars, int fd)
{
  printf("sizeof = %zu\n", sizeof(t_pixel));
  t_pixel px[pars->width];
  int i;
  int j;
  
  i = pars->height;
  while (--i >= 0)
  {
    j = 0;
    while (j < pars->width) 
    {
      int color = ft_get_px_from_image(&pars->params->data, j, i);
      px[j].b = color >> 0;
      px[j].g = color >> 8;
      px[j].r = color >> 16;
      ++j;
    }
    write(fd, px, sizeof(px));
  }
}

void  ft_create_bmp(t_pars *pars)
{
  char *name;
  t_info_header info;
  t_file_header file;

  name = (char*)"Cub3D.bmp";  int fd;
  fd = open(name, O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
  ft_create_header(pars, &info, &file);
  write(fd, &file, sizeof(t_file_header));
  write(fd, &info, sizeof(t_info_header));
  ft_generate_image(pars, fd);
  close(fd);
}

void ft_save_bmp(char *argv, t_pars *pars)
{
  size_t n;

  if (ft_strlen("--save") != (n = ft_strlen(argv)))
    ft_error("The second argument is not valid\n");
  if (ft_strncmp("--save", argv, n) != 0)
    ft_error("The second argument is not valid\n");
  pars->save = 1;
  printf("C est bien save\n");
}
