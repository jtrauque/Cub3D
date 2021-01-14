#include "cub3d.h"


int  deal_key_release(int key, t_pars *pars)
{
  printf("Key %d releaes\n", key);
  if (key == GO_FORWARD) 
    pars->forward = 0;
  if (key == GO_BACKWARD) 
    pars->backward = 0;
  if (key == TURN_RIGHT) 
    pars->right = 0;
  if (key == TURN_LEFT) 
    pars->left = 0;
  return (0);
}
int  deal_key(int key, t_pars *pars)
{
  ft_putchar('X');
  ft_putnbr(key);
  printf("player map[%d][%d]\n", (int)(pars->px), (int)pars->py);
  printf("player + dir map[%d][%d]\n", (int)(pars->px + pars->dx), (int)pars->py);
  if (key == 65307)
    mlx_loop_end(pars->params->mlx_ptr);
  ft_move(key, pars);
  ft_look_at(pars, pars->params);
  return (0);
}

void  ft_rotate(t_pars *pars, float n)
{
  float save_dir_x; 
  float save_plane_x;
  float rotate_speed;

  rotate_speed = 0.1;
  save_dir_x = pars->dx;
  save_plane_x = pars->plane_x;
  pars->dx = pars->dx * cos(n * rotate_speed) - pars->dy * sin(n * rotate_speed);
  printf("pars->dx rotate = %f\n", pars->dx);
  pars->dy = save_dir_x * sin(n * rotate_speed) + pars->dy * cos(n * rotate_speed);
  printf("pars->dy rotate = %f\n", pars->dy);
  pars->plane_x = pars->plane_x * cos(n * rotate_speed) - pars->plane_y * sin(n * rotate_speed); 
  printf("pars->plane_x rotate = %f\n", pars->plane_x);
  pars->plane_y = save_plane_x * sin(n * rotate_speed) + pars->plane_y * cos(n * rotate_speed);
  printf("pars->plane_y rotate = %f\n", pars->plane_y);
}

void  ft_move(int key, t_pars *pars)
{
  pars->speed = 0.1;
  if (key == GO_BACKWARD)
    pars->backward = 1;
  if (key == GO_FORWARD)
    pars->forward = 1;
  if (key == TURN_RIGHT)
    pars->right = 1;
  if (key == TURN_LEFT)
    pars->left = 1;
}
