#include "cub3d.h"


static int   ft_find(char c, char *str)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (str[i])
  {
    if (str[i] == c)
      count++;
    i++;
  }
  return (count);
}

int  ft_map_valide(char *elements, t_pars *pars)
{
  int i;
  char *caracteres;

  caracteres = "012NSEW ";
  i = 0;
  if (elements[i] != '1' && elements[i] != ' ')
  {
    printf("diff de 1 ? elements[%d] = %c\n", i, elements[i]);
    return (0);
  }
  while (elements[i])
  {
    if (ft_find(elements[i], caracteres) == 0)
    {
      printf("erreur find elements[%d] = %c\n", i, elements[i]);
      return (0);
    }
    if (ft_find(elements[i], caracteres + 3) != 0)
    {
      pars->py = i;
    }

    if (elements[i] == '0' && elements[i + 1] == ' ')
    {
      printf("erreur wall elements[%d] = %c\n", i, elements[i]);
      return (0);
    }
    else if (elements[i] == ' ')
      elements[i] = 1;
    // printf("while - elements[%d] = %c\n", i, elements[i]);
    i++;
  }
  if (elements[i - 1] != '1')
  {
    printf("1 at the end ? elements[%d] = %c\n", i, elements[i]);
    return (0);
  }
  //  printf("elements [%s]\n", elements);
  return (1);
}

void ft_map_save(t_params params, char *elements, t_pars *pars)
{
//  int n;

  (void) params;
  if (ft_map_valide(elements, pars) != 0)
  {
  //  printf("retour map valide : %d\n", n);
 //   printf("elements : %s\n", elements);
  //  printf("pars->map : %s\n", pars->map);
    if (!(pars->map = ft_strnjoin(pars->map, elements, ft_strlen(elements))))
      return;
    if (!(pars->map = ft_strnjoin(pars->map, "\n", 1)))
      return;
   // printf("pars->map : %s\n", pars->map);
  }
  else 
    ft_error_map("map error\n", pars);
}

void ft_global_map_check(t_pars *pars)
{
  int j;
  char *obs;
  int count;

  obs = "NSWE";
  j = 0;
  count = 0;
  while (obs[j])
  {
    if(ft_find(obs[j], pars->map) == 1)
      count++;
    if(ft_find(obs[j], pars->map) > 1)
      ft_error_map("map error\n", pars);
    j++;
  }
  if (count > 1 || count == 0)
    ft_error_map("map error\n", pars);
}
