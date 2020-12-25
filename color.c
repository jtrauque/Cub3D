
#include "cub3d.h"

int ft_rgb(char *elements)
{
  int i;
  int R;
  int G;
  int B;

  i = 2;
  R = 0;
  G = 0;
  B = 0;
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    R = R * 10 + (elements[i] - '0');
    i++;
  }
  i++;
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    G = G * 10 + (elements[i] - '0');
    i++;
  }
  i++;
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    B = B * 10 + (elements[i] - '0');
    i++;
  }
  return (65536 * R + 256 * G + B);
}

void  ft_color(t_params *params, char *elements, t_pars *pars)
{
  int i;

  i = 0;
  (void)params;
  if (elements[i] == 'F' && elements[i + 1] == ' ')
  {
    i += ft_space(elements + i);
    pars->color_f = ft_rgb(elements + i);
  }
  else if (elements[i] == 'C' && elements[i + 1] == ' ')
  {
    i += ft_space(elements + i);
    pars->color_c = ft_rgb(elements + i);
  }
   else
    ft_error("error color\n");
}
