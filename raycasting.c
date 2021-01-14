#include "cub3d.h"


void  ft_sprite_distance(t_obs *obs, t_pars *pars)
{
  pars->is_a_sprite = 1;
  pars->is_a_sprite_x = obs->map_x;
  pars->is_a_sprite_y = obs->map_y;
  obs->sprite_true_dist = (obs->map_y - pars->py + (1 - obs->step_y) / 2) / obs->raydir_y;
}

int   ft_hit(t_obs *obs, t_pars *pars)
{
  if (obs->dist_x < obs->dist_y)
  {
    obs->dist_x += obs->xa;
    obs->map_x += obs->step_x;
    if (obs->step_x == 1)
      obs->side = 0;
    else if (obs->step_x == -1)
      obs->side = 1;
  }
  else 
  {
    obs->dist_y += obs->ya;
    obs->map_y += obs->step_y;
    if (obs->step_y == 1)
      obs->side = 2;
    else if (obs->step_y == -1)
      obs->side = 3;
  }
  if (pars->map[obs->map_y][obs->map_x] == '1')
    return (1);
  if (pars->map[obs->map_y][obs->map_x] == '2')
    ft_sprite_distance(obs, pars);
  return (0);
}

void  ft_step(t_obs *obs, t_pars *pars)
{
  if (obs->raydir_x < 0)
  {
    obs->step_x = -1;
    obs->dist_x = (pars->px - obs->map_x) * obs->xa;
  }
  else
  {
    obs->step_x = 1;
    obs->dist_x = (obs->map_x + 1.0 - pars->px) * obs->xa; 
  }
  if (obs->raydir_y < 0)
  {
    obs->step_y = -1;
    obs->dist_y = (pars->py - obs->map_y) * obs->ya;
  }
  else
  {
    obs->step_y = 1;
    obs->dist_y = (obs->map_y + 1.0 - pars->py) * obs->ya; 
  }
}
void  ft_detect_obs(t_pars *pars, t_obs *obs)
{
  int hit = 0;

  obs->xa = fabs(1 / obs->raydir_x);
  obs->ya = fabs(1 / obs->raydir_y);
  ft_step(obs, pars);
  while (hit == 0)
    hit = ft_hit(obs, pars);
  if (obs->side == 0 || obs->side == 1)
    obs->true_dist = (obs->map_x - pars->px + (1 - obs->step_x) / 2) / obs->raydir_x;
  else
    obs->true_dist = (obs->map_y - pars->py + (1 - obs->step_y) / 2) / obs->raydir_y;
   // printf("distance = %f\n", obs->true_dist);
}

void ft_distance_init(t_obs *obs, t_pars *pars)
{
  obs->camera = (2. * obs->pix / (double)pars->width) - 1;
  obs->raydir_y = pars->dy + pars->plane_y * obs->camera;
  obs->raydir_x = pars->dx + pars->plane_x * obs->camera;
  obs->map_x = (int)pars->px;
  obs->map_y = (int)pars->py;
  obs->heigth_column_PJ = (int)(pars->height / obs->true_dist);
  obs->draw_start = (-obs->heigth_column_PJ / 2) + (pars->height / 2);
  obs->draw_end = (obs->heigth_column_PJ / 2) + (pars->height / 2);
  if (obs->draw_start < 0)
    obs->draw_start = 0;
  if (obs->draw_end >= pars->height)
    obs->draw_end = pars->height - 1;
}
