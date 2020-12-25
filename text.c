#include "cub3d.h"

void ft_text_n(t_params params, char *elements, t_pars *pars)
{
  char *relative_path;
  int img_width;
  int img_height;
  int i;

  i = 1;
  if (elements[i] == 'O' && elements[i + 1] == ' ')
  {
//    ft_xpm_to_image(params, elements, pars->text_n);
    i += ft_space(elements + i);
  relative_path = elements + i;
   pars->text_n = mlx_xpm_file_to_image(params.mlx_ptr, relative_path, &img_width, &img_height);
  }
  else 
    ft_error("error texture\n");
}

void ft_text_s(t_params params, char *elements, t_pars *pars)
{
  char *relative_path;
  int img_width;
  int img_height;
  int i;

  i = 1;
  if (elements[i] == 'O' && elements[i + 1] == ' ')
  {
  //  ft_xpm_to_image(params, elements, pars->text_s);
    i += ft_space(elements + i);
    relative_path = elements + i;
    pars->text_s = mlx_xpm_file_to_image(params.mlx_ptr, relative_path, &img_width, &img_height);
  }
  else if (elements[i] == ' ') 
  {
    //ft_xpm_to_image(params, elements, pars->text_sprite);
   i += ft_space(elements + i);
  relative_path = elements + i;
   pars->text_sprite = mlx_xpm_file_to_image(params.mlx_ptr, relative_path, &img_width, &img_height);
  }
  else 
    ft_error("error texture\n");
}

/*
void  ft_xpm_to_image(t_params params, char *elements, void **text)
{
  char *relative_path;
  int img_width;
  int img_height;
  int i;

  i = 1;
  i += ft_space(elements + i);
  relative_path = elements + i;
  *text = mlx_xpm_file_to_image(params.mlx_ptr, relative_path, &img_width, &img_height);
}*/

void ft_text_w(t_params params, char *elements, t_pars *pars)
{
  char *relative_path;
  int img_width;
  int img_height;
  int i;

  i = 1;
  if (elements[i] == 'O' && elements[i + 1] == ' ')
  {
    i += ft_space(elements + i);
    relative_path = elements + i;
    pars->text_w = mlx_xpm_file_to_image(params.mlx_ptr, relative_path, &img_width, &img_height);
  }
  else 
    ft_error("error texture\n");
}

void ft_text_e(t_params params, char *elements, t_pars *pars)
{
  char *relative_path;
  int img_width;
  int img_height;
  int i;

  i = 1;
  if (elements[i] == 'O' && elements[i + 1] == ' ')
  {
    i += ft_space(elements + i);
    relative_path = elements + i;
    pars->text_w = mlx_xpm_file_to_image(params.mlx_ptr, relative_path, &img_width, &img_height);
  }
  else 
    ft_error("error texture\n");
}
