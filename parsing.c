
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

  (void) params;
  i = 2;
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    pars->width = pars->width * 10 + (elements[i] - '0');
    i++;
  }
  i++;
  while (elements[i] && (elements[i] >= '0' && elements[i] <= '9'))
  {
    pars->height = pars->height * 10 + (elements[i] - '0');
    i++;
  }
}
