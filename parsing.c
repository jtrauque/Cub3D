
#include "cub3d.h"

typedef void (*t_fn_parsing_t)(t_params *params, char *str,t_pars *p);
t_fn_parsing_t g_parsing[8] = {ft_resolution, ft_text_n, ft_text_s, ft_text_w, ft_text_e, ft_color, ft_color, ft_map_save};

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

void ft_parsing(int fd, t_pars *pars, t_params *params)
{
  char *elements;
  int i;
  int n;
  
  elements = NULL;
  while ((get_next_line(fd, &elements)) > 0)
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
    // printf("pars->count = %d\n", pars->count);
    if (i == 7 && pars->count == 8)
      g_parsing[i](params,elements, pars);
    else if (i != - 1 && i != 7)
      g_parsing[i](params,elements + n, pars);
    else
      ft_error("error elements\n");
    free(elements);
  }
}

void ft_resolution(t_params *params, char *elements, t_pars *pars)
{
  int i;
  int width_max;
  int height_max;

  i = 1;
  pars->count += 1;
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
