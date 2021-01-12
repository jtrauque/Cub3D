#include "cub3d.h"

void ft_text_n(t_params *params, char *elements, t_pars *pars)
{
  char *relative_path;
  int i;

  i = 1;
  if (elements[i] == 'O' && elements[i + 1] == ' ')
  {
    //    ft_xpm_to_image(params, elements, pars->text_n);
    i += 1;
    printf("space = %d\n", ft_space(elements + i));
    i += ft_space(elements + i);
    relative_path = elements + i;
    printf("i= %d\n", i);
    printf("path = %s\n", elements + i);
    pars->text_n.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path, &pars->text_n.img_width, &pars->text_n.img_height);
    pars->text_n.data = (unsigned int *)mlx_get_data_addr(pars->text_n.img, &pars->text_n.bpp, &pars->text_n.size_line, &pars->text_n.endian);
  }
  else 
    ft_error("error texture\n");
}

void ft_text_s(t_params *params, char *elements, t_pars *pars)
{
  char *relative_path;
  int i;

  i = 1;
  if (elements[i] == 'O' && elements[i + 1] == ' ')
  {
    i += 1;
    i += ft_space(elements + i);
    relative_path = elements + i;
    printf("i= %d\n", i);
    printf("path = %s\n", elements + i);
    pars->text_s.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path, &pars->text_s.img_width, &pars->text_s.img_height);
    pars->text_s.data = (unsigned int *)mlx_get_data_addr(pars->text_s.img, &pars->text_s.bpp, &pars->text_s.size_line, &pars->text_s.endian);
  }
  else if (elements[i] == ' ') 
  {
    i += 1;
    i += ft_space(elements + i);
    relative_path = elements + i;
    printf("i= %d\n", i);
    printf("path = %s\n", elements + i);
    pars->text_sprite.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path, &pars->text_sprite.img_width, &pars->text_sprite.img_height);
    pars->text_sprite.data = (unsigned int *)mlx_get_data_addr(pars->text_sprite.img, &pars->text_sprite.bpp, &pars->text_sprite.size_line, &pars->text_sprite.endian);
  }
  else 
    ft_error("error texture\n");
}

void ft_text_w(t_params *params, char *elements, t_pars *pars)
{
  char *relative_path;
  int i;

  i = 1;
  if (elements[i] == 'E' && elements[i + 1] == ' ')
  {
    i += 1;
    i += ft_space(elements + i);
    relative_path = elements + i;
    printf("i= %d\n", i);
    printf("path = %s\n", elements + i);
    pars->text_w.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path, &pars->text_w.img_width, &pars->text_w.img_height);
    pars->text_w.data = (unsigned int *)mlx_get_data_addr(pars->text_w.img, &pars->text_w.bpp, &pars->text_w.size_line, &pars->text_w.endian);
  }
  else 
    ft_error("error texture\n");
}

void ft_text_e(t_params *params, char *elements, t_pars *pars)
{
  char *relative_path;
  int i;

  i = 1;
  if (elements[i] == 'A' && elements[i + 1] == ' ')
  {
    i += 1;
    i += ft_space(elements + i);
    relative_path = elements + i;
    printf("i= %d\n", i);
    printf("path = %s\n", elements + i);
    pars->text_e.img = mlx_xpm_file_to_image(params->mlx_ptr, relative_path, &pars->text_e.img_width, &pars->text_e.img_height);
    pars->text_e.data = (unsigned int *)mlx_get_data_addr(pars->text_e.img, &pars->text_e.bpp, &pars->text_e.size_line, &pars->text_e.endian);
  }
  else 
    ft_error("error texture\n");
}
