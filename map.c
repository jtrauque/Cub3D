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

char  *ft_map_valide(char *elements, t_pars *pars, t_params *params )
{
  int i;
  char *caracteres;
  char *temp;

  caracteres = "012NSEW ";
  temp = elements;

  i = 0;
  //  printf("arrivee dans map [%s]\n", elements);
  //  printf("elements[%d] = [%c]\n", i, elements[i]);
  //  printf("temp[%d] = [%c]\n", i, temp[i]);
  //  while (temp[i] == ' ')
  //   temp[i++] = 1;
  if (temp[i] != '1' && temp[i] != ' ')
  {
    printf("diff de 1 ? elements[%d] = %c\n", i, elements[i]);
    return (NULL);
  }
  while (temp[i])
  {
    if (temp[i] == '0' && temp[i + 1] == ' ')
    {
      printf("erreur wall elements[%d] = %c\n", i, elements[i]);
      return (NULL);
    }
    if (temp[i] == ' ')
    {
      temp[i] = '1';
      printf("WHAT\n");
    }
    printf("before temp[%d] = [%c]\n", i, temp[i]);
    if (ft_find(temp[i], caracteres) == 0)
    {
      printf("erreur find elements[%d] = [%c]\n", i, temp[i]);
      return (NULL);
    }
    if (ft_find(temp[i], caracteres + 3) != 0)
    {
      pars->py = i;
    }
    // printf("while - elements[%d] = %c\n", i, elements[i]);
    //    printf("temp[%d] = %c\n", i, temp[i]);
    i++;
  }
  if (temp[i - 1] != '1')
  {
    printf("1 at the end ? elements[%d] = %c\n", i, elements[i]);
    return (NULL);
  }
  if (i > params->map_w)
    params->map_w = i;
  printf("sortie de map [%s]\n", temp);
  //  printf("elements [%s]\n", elements);
  return (temp);
}

void ft_map_save(t_params *params, char *elements, t_pars *pars)
{
  //  int n;
  char *tmp;
  //  char *tmp_s;
  //  int i;

  //  i = 0;
  if ((tmp = ft_map_valide(elements, pars, params)) != NULL)
  {
    //  printf("retour map valide : %d\n", n);
    //   printf("tmpsave : %s\n", tmp);
    //  printf("pars->map : %s\n", pars->map);
    if (!(pars->map = ft_strnjoin(pars->map, tmp, ft_strlen(tmp))))
      return;
    if (!(pars->map = ft_strnjoin(pars->map, "\n", 1)))
      return;
    // printf("pars->map : %s\n", pars->map);
  }
  else 
    ft_error_map("map error\n", pars);
}

char **ft_global_map_check(t_pars *pars, t_params *params)
{
  int j;
  char *obs;
  int count;
  char **map;

  obs = "NSWE";
  j = 0;
  count = 0;
  while (obs[j])
  {
    if(ft_find(obs[j], pars->map) == 1)
    {
      count++;
    }
    if(ft_find(obs[j], pars->map) > 1)
      ft_error_map("map error\n", pars);
    j++;
  }
  if (count > 1 || count == 0)
    ft_error_map("map error\n", pars);
  map = ft_split_one(pars->map,'\n', params);
  return (map);
}

void  ft_direction(t_pars *pars, char c)
{
  if(c == 'N')
  {
    printf("di pars->px : %f\n", pars->px);
    printf("di pars->py : %f\n", pars->py);
    pars->dx = pars->px;
    pars->dy = pars->py + 1.0;
    printf("di pars->dx : %f\n", pars->dx);
    printf("di pars->dy : %f\n", pars->dy);
  }
  else if(c == 'S')
  {
    pars->dx = pars->px;
    pars->dy = pars->py - 1.0;
  }
  else if(c == 'W')
  {
    pars->dx = pars->px - 1.0;
    pars->dy = pars->py;
  } 
  else if(c == 'E')
  {
    pars->dx = pars->px + 1.0;
    pars->dy = pars->py;
  }
}

void  ft_location_player(t_pars *pars, char **map) 
{
  int x;
  int y;
  char *obs;

  y = 0;
  obs = "NSWE";
  while (map[y])
  {
    x = 0;
    while (map[y][x])
    {
      if(ft_find(map[y][x], obs) == 1)
      {
        pars->py = y;
        pars->px = x;
        ft_direction(pars,map[y][x]);
        return;
      }
      x++;
    }
    y++;
  }
}
