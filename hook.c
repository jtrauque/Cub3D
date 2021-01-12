#include "cub3d.h"

int  toto3(t_pars *pars) {
  (void)pars;
  mlx_loop_end(pars->params->mlx_ptr);
  return printf("GOT A DELETE BRO << < < < < <<< \n");
}
int  minimize_win(t_pars *pars) {
  ft_look_at(pars, pars->params);
  return (0);
}
int  game_loop(t_pars *pars)
{
  if (pars->forward == 1) 
  {
    if (pars->map[(int)pars->py][(int)(pars->px + pars->dx * pars->speed)] == '0')
      pars->px += pars->dx * pars->speed;
    if (pars->map[(int)(pars->py + pars->dy * pars->speed)][(int)pars->px] == '0')
      pars->py += pars->dy * pars->speed;
  }
  if (pars->backward == 1)
  {
    if (pars->map[(int)pars->py][(int)(pars->px - pars->dx * pars->speed)] == '0')
      pars->px -= pars->dx * pars->speed;
    if (pars->map[(int)(pars->py - pars->dy * pars->speed)][(int)pars->px] == '0')
      pars->py -= pars->dy * pars->speed;
  }
  if(pars->left == 1)
    ft_rotate(pars, -1.);
  if(pars->right == 1)
    ft_rotate(pars, 1.);
  ft_look_at(pars, pars->params);
  return 0;
}

void  ft_manage_mlx(t_params *params, t_pars *pars)
{
  mlx_hook(params->win_ptr, 2 , 1<<0, deal_key, pars);
  mlx_hook(params->win_ptr, 3 , 1L<<1, deal_key_release, pars);
  mlx_hook(params->win_ptr, 12 , 1L<<15, minimize_win, pars);
  mlx_hook(params->win_ptr, 35 ,0, toto3, pars);
  mlx_do_key_autorepeatoff(params->mlx_ptr);
  mlx_loop_hook(params->mlx_ptr, game_loop, pars);
}

void ft_manage_mlx_destroy(t_params *params, t_pars *pars)
{
  mlx_destroy_image(params->mlx_ptr, params->data.img);
  mlx_destroy_image(params->mlx_ptr, pars->text_n.img);
  mlx_destroy_image(params->mlx_ptr, pars->text_s.img);
  mlx_destroy_image(params->mlx_ptr, pars->text_e.img);
  mlx_destroy_image(params->mlx_ptr, pars->text_w.img);
  mlx_destroy_image(params->mlx_ptr, pars->text_sprite.img);
}
