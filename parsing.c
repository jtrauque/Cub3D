
#include "cub3d.h"

int  ft_identify_type(char c)
{
  char *type;
  int i;

  type = "RNSWEFC1";
  i = 0;
  while (type[i])
  {
    if (type[i] == c)
      return (i);
    i++;
  }
  return (-1);
}

void ft_resolution(t_params *params, char *elements, t_pars *pars)
{
  int i;
  int width_max;
  int height_max;

  i = 1;
  i += ft_space(elements + i);
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    pars->width = pars->width * 10 + (elements[i] - '0');
    i++;
  }
  i += ft_space(elements + i);
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    pars->height = pars->height * 10 + (elements[i] - '0');
    i++;
  }
  mlx_get_screen_size(params->mlx_ptr, &width_max, &height_max);
  if (pars->width > width_max)
  {
    printf("window width resized\n");
    pars->width = width_max;
  }
  if (pars->height > height_max)
  {
    printf("window height resized\n");
    pars->height = height_max;
  }
  if (pars->width == 0 || pars->height == 0)
    ft_error("error resolution\n");
}
