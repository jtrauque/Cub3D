
#include "cub3d.h"

int ft_rgb(char *elements)
{
  int i;
  int R;
  int G;
  int B;

  i = 0;
  R = 0;
  G = 0;
  B = 0;
  // i += ft_space(elements + i);
    // printf("elements R = %s\n", elements + i);
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    R = R * 10 + (elements[i] - '0');
    i++;
  }
  i++;
  i += ft_space(elements + i);
    // printf("espace 1 = %d\n", i);
    // printf("elements G= %s\n", elements + i);
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    G = G * 10 + (elements[i] - '0');
    i++;
  }
  i++;
  i += ft_space(elements + i);
    // printf("espace 2 = %d\n", i);
    // printf("elements B= %s\n", elements + i);
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

  i = 1;
  pars->count += 1;
  (void)params;
  // printf("elements[%d] = %c\n", i, elements[i]);
  if (elements[0] == 'F' && elements[1] == ' ')
  {
    // i += 1;
    i += ft_space(elements + i);
    // printf("espace floor = %d\n", i);
    // printf("elements = %s\n", elements);
    pars->color_f = ft_rgb(elements + i);
  }
  else if (elements[0] == 'C' && elements[1] == ' ')
  {
    // i += 1;
    i += ft_space(elements + i);
    // printf("espace sky = %d\n", i);
    // printf("elements = %s\n", elements);
    pars->color_c = ft_rgb(elements + i);
  }
   else
    ft_error("error color\n");
}
