#include "cub3d.h"


void  ft_sprite_init(t_pars *pars, t_sprite *sprite)
{
  // printf("sprite x = %f\n", sprite->sprite_x);
  // printf("sprite y = %f\n", sprite->sprite_y);
  sprite->init = 1.0 / (pars->plane_x * pars->dy - pars->dx * pars->plane_y); 
  // printf("init = %f\n", sprite->init);
  sprite->next_x = sprite->init * (pars->dy * sprite->sprite_x - pars->dx * sprite->sprite_y); 
  // printf("next_x = %f\n", sprite->next_x);
  sprite->next_y = sprite->init * (-pars->plane_y * sprite->sprite_x + pars->plane_x * sprite->sprite_y);  
  sprite->sprite_screen = (int)((pars->width / 2) * (1 + sprite->next_x / sprite->next_y)); 
  // printf("next_y = %f\n", sprite->next_y);
  sprite->heigth_column_PJ = abs((int)(pars->height / sprite->next_y)); 
  // printf("sprite height = %d\n", sprite->heigth_column_PJ);
  sprite->draw_start = (-sprite->heigth_column_PJ / 2) + (pars->height / 2);
  sprite->draw_end = (sprite->heigth_column_PJ / 2) + (pars->height / 2);
  if (sprite->draw_start < 0)
    sprite->draw_start = 0;
  if (sprite->draw_end >= pars->height)
    sprite->draw_end = pars->height - 1;
  // printf("sprite draw_start = %d\n", sprite->draw_start);
  // printf("sprite draw_end = %d\n", sprite->draw_end);
  sprite->width_column_PJ = abs((int)(pars->height / sprite->next_y)); 
  sprite->width_draw_start = (-sprite->width_column_PJ / 2) + sprite->sprite_screen;
  sprite->width_draw_end = (sprite->width_column_PJ / 2) + sprite->sprite_screen;
  if (sprite->width_draw_start < 0)
    sprite->width_draw_start = 0;
  if (sprite->width_draw_end >= pars->width)
    sprite->width_draw_end = pars->width - 1;
  // printf("sprite width draw_start = %d\n", sprite->width_draw_start);
  // printf("sprite width draw_end = %d\n", sprite->width_draw_end);
}

void  ft_sort_sprite(t_pars *pars)
{
  int i;
  int first;
  int second;
  t_vecteur tmp;

  i = 0;
  while (i < pars->sprite_nbr) // && i + 1 != pars->sprite_nbr
  {
    first = ((pars->px - pars->sprite[i].x) * (pars->px - pars->sprite[i].x) + (pars->py - pars->sprite[i].y) * (pars->py - pars->sprite[i].y));
    second = ((pars->px - pars->sprite[i + 1].x) * (pars->px - pars->sprite[i + 1].x) + (pars->py - pars->sprite[i + 1].y) * (pars->py - pars->sprite[i + 1].y));
    if (first < second)
    {
      tmp = pars->sprite[i];
      pars->sprite[i] = pars->sprite[i + 1];
      pars->sprite[i + 1] = tmp;
      i = 0;
    }
    else
      i++;
  }
}

void  ft_sprite_loop(t_pars *pars, t_sprite *sprite, t_params *params)
{
  int stripe;
  int start;
  int color;
  int n;

  // sprite->sprite_x = pars->sprite[sprite->n].x - (pars->px - 0.5);
  // sprite->sprite_y = pars->sprite[sprite->n].y - (pars->py - 0.5);
  // printf("numero sprite = %d\n", sprite->n);
  sprite->sprite_x = pars->sprite[sprite->n].x - (pars->px) ; // - 0.5);
  sprite->sprite_y = pars->sprite[sprite->n].y - (pars->py) ; // - 0.5);
  ft_sprite_init(pars, sprite);
  stripe = sprite->width_draw_start;
  // printf("stripe = %d\n", stripe);
  // printf("sprite width_draw_end = %d\n", sprite->width_draw_end);
  while (stripe < sprite->width_draw_end)
  {
    sprite->draw_x = (int)(pars->text_sprite.size_line * (stripe - (-sprite->width_column_PJ / 2 + sprite->sprite_screen)) * pars->text_sprite.img_width / sprite->width_column_PJ) / pars->text_sprite.size_line;
    // printf("draw x = %d\n", sprite->draw_x);
    if (sprite->next_y > 0 && stripe > 0 && stripe < pars->width)
    {
      start = sprite->draw_start;
      while (start < sprite->draw_end)
      {
        n = start * pars->text_sprite.size_line - pars->height * (pars->text_sprite.size_line / 2) + sprite->heigth_column_PJ * (pars->text_sprite.size_line / 2);
        // printf("n = %d\n", n);
        sprite->draw_y = ((n * pars->text_sprite.img_height) / sprite->heigth_column_PJ) / pars->text_sprite.size_line; 
        // printf("draw y = %d\n", sprite->draw_y);
        color = ft_get_px_from_image(&pars->text_sprite, sprite->draw_x , sprite->draw_y);
        if (color != 0)
          ft_put_px_in_image(&params->data, stripe , start , color);
        start++;
      }
    }
    stripe++;
  }
}
