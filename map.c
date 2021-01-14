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

  (void)pars;
  i = 0;
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
      //     printf("WHAT\n");
    }
    //  printf("before temp[%d] = [%c]\n", i, temp[i]);
    if (ft_find(temp[i], caracteres) == 0)
    {
      printf("erreur find elements[%d] = [%c]\n", i, temp[i]);
      return (NULL);
    }
    // if (ft_find(temp[i], caracteres + 3) != 0)
    // pars->py = i;
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
  //  printf("sortie de map [%s]\n", temp);
  //  printf("elements [%s]\n", elements);
  return (temp);
}

void ft_map_save(t_params *params, char *elements, t_pars *pars)
{
  char *tmp;
  printf("MAP\n");
  if ((tmp = ft_map_valide(elements, pars, params)) != NULL)
  {
    if (!(pars->map_tmp = ft_strnjoin(pars->map_tmp, tmp, ft_strlen(tmp))))
      return;
    if (!(pars->map_tmp = ft_strnjoin(pars->map_tmp, "\n", 1)))
      return;
  }
  else 
    ft_error_map("map error\n", pars);
}

char **ft_global_map_check(t_pars *pars, t_params *params)
{
  int j;
  int i;
  char *obs;
  int count;
  // char **map;

  obs = "NSWE";
  j = 0;
  count = 0;
  i= 0;
  if (!pars->map_tmp)
    ft_error_map("No Map ???\n", pars);
  while (obs[j])
  {
    if(ft_find(obs[j], pars->map_tmp) == 1)
    {
      count++;
    }
    if(ft_find(obs[j], pars->map_tmp) > 1)
      ft_error_map("map error\n", pars);
    j++;
  }
  if (count > 1 || count == 0)
    ft_error_map("map error - too much or no players\n", pars);
  pars->map = ft_split_one(pars->map_tmp,'\n', params);
  while (pars->map[0][i])
  {
    if (pars->map[0][i] != '1')
      ft_error_map("map error - wall missing\n", pars);
    i++;
  }
  i= 0;
  printf("map h : %d\n", params->map_h);
  while (pars->map[params->map_h - 1][i])
  {
    if (pars->map[params->map_h - 1][i] != '1')
      ft_error_map("map error - wall missing\n", pars);
    i++;
  }
  return (pars->map);
}

void  ft_direction(t_pars *pars, char c)
{
  if(c == 'N')
  {
    pars->dx = 0;
    pars->dy = -1.0;
    pars->plane_x = 1.0;
    pars->plane_y = 0;
  }
  else if(c == 'S')
  {
    pars->dx = 0;
    pars->dy = 1.0;
    pars->plane_x = -1.0;
    pars->plane_y = 0;
  }
  else if(c == 'W')
  {
    pars->dx = -1.0;
    pars->dy = 0;
    pars->plane_x = 0;
    pars->plane_y = -1.0;
  } 
  else if(c == 'E')
  {
    pars->dx = 1.0;
    pars->dy = 0;
    pars->plane_x = 0;
    pars->plane_y = 1.0;
  }
}

void   ft_count_sprite(t_pars *pars)
{
  int x;
  int y;
  int i;

  y = 0;
  i = 0;
  while (pars->map[y])
  {
    x = 0;
    while (pars->map[y][x])
    {
      if(pars->map[y][x] == '2')
      {
        i++;
      }
      x++;
    }
    y++;
  }
  pars->sprite_nbr = i;
}

void  ft_location_player(t_pars *pars) 
{
  int x;
  int y;
  int i;

  y = 0;
  i = 0;
  ft_count_sprite(pars);
  if (!(pars->sprite = malloc(sizeof(t_vecteur) * (pars->sprite_nbr + 1))))
    return;
  while (pars->map[y])
  {
    x = 0;
    while (pars->map[y][x])
    {
      if(ft_find(pars->map[y][x], "NSWE") == 1)
      {
        printf("player x = %d\n", x);
        printf("player y = %d\n", y);
        pars->py = (float)y + .5;
        pars->px = (float)x + .5;
        ft_direction(pars,pars->map[y][x]);
      }
      if(pars->map[y][x] == '2')
      {
        pars->sprite[i].y = y;
        pars->sprite[i].x = x;
        i++;
      }
      x++;
    }
    y++;
  }
}
