#include "cub3d.h"


int  deal_key(int key, t_pars *pars)
{
  printf("params: %p\n", pars->params);
  // (void) params;
  ft_putchar('X');
  ft_putnbr(key);
  printf("player map[%d][%d]\n", (int)(pars->px), (int)pars->py);
  printf("player + dir map[%d][%d]\n", (int)(pars->px + pars->dx), (int)pars->py);
  if (key == 65307)
    exit(1);
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
  pars->dy = save_dir_x * sin(n * rotate_speed) + pars->dy * cos(n * rotate_speed);
  pars->plane_x = pars->plane_x * cos(n * rotate_speed) - pars->plane_y * sin(n * rotate_speed); 
  pars->plane_y = save_plane_x * sin(n * rotate_speed) + pars->plane_y * cos(n * rotate_speed);

}

void  ft_move(int key, t_pars *pars)
{
  float speed;
  speed = 0.1;
  if (key == 65364) // fleche bas
  {
    if (pars->map[(int)pars->py][(int)(pars->px - pars->dx * speed)] == '0')
      pars->px -= pars->dx * speed;
    if (pars->map[(int)(pars->py - pars->dy * speed)][(int)pars->px] == '0')
      pars->py -= pars->dy * speed;
  }
  if (key == 65362) // fleche haut
  {
    if (pars->map[(int)pars->py][(int)(pars->px + pars->dx * speed)] == '0')
      pars->px += pars->dx * speed;
    if (pars->map[(int)(pars->py + pars->dy * speed)][(int)pars->px] == '0')
      pars->py += pars->dy * speed;
  }
  if (key == 65363) // fleche droite
  {
    ft_rotate(pars, 1.);
    // if (pars->map[(int)pars->py][(int)(pars->px + pars->plane_x * speed)] == '0')
    //   pars->px += pars->plane_x * speed;
    // if (pars->map[(int)(pars->py + pars->plane_y * speed)][(int)pars->px] == '0')
    //   pars->py += pars->plane_y * speed;
  }
  if (key == 65361) // fleche gauche
  {
    ft_rotate(pars, -1.);
    // if (pars->map[(int)pars->py][(int)(pars->px - pars->plane_x * speed)] == '0')
    //   pars->px -= pars->plane_x * speed;
    // if (pars->map[(int)(pars->py - pars->plane_y * speed)][(int)pars->px] == '0')
    //   pars->py -= pars->plane_y * speed;
  }
}
