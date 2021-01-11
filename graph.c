#include "cub3d.h"

void ft_apply_text_on_wall(t_pars *pars, t_obs *obs, t_data *text)
{
  double column_x;

  if (obs->side == 2 || obs->side == 3)
    column_x = (double)pars->px + obs->true_dist * obs->raydir_x;
  else 
    column_x = (double)pars->py + obs->true_dist * obs->raydir_y;
  column_x -= (int)(column_x);
  obs->text_x = (int)(column_x * (double)text->img_width);
  if ((obs->side == 0 || obs->side == 1) && obs->raydir_x > 0)
    obs->text_x = text->img_width - obs->text_x - 1;
  if ((obs->side == 2 || obs->side == 3) && obs->raydir_y < 0)
    obs->text_x = text->img_width - obs->text_x - 1;
}

void   ft_side_pick(t_pars *pars, t_obs *obs)
{
  if (obs->side == 1)
    obs->text = &pars->text_w;
  if (obs->side == 3)
    obs->text = &pars->text_n;
  if (obs->side == 0)
    obs->text = &pars->text_e;
  if (obs->side == 2)
    obs->text = &pars->text_s;
  ft_apply_text_on_wall(pars, obs, obs->text);
}

void ft_background(t_pars *pars, t_params *params)
{
  int middle_screen;
  int y2;
  float f;

  middle_screen = pars->height /2;
  y2 = 0;
  f = 0.0;
  while (f < pars->width) {
    y2 = 0;
    while (y2 < pars->height / 2) {
      ft_put_px_in_image(&params->data, f, middle_screen + y2 , pars->color_c);
      ft_put_px_in_image(&params->data, f, middle_screen - y2 , pars->color_f);
      y2++;
    }
    f += 1;
  }

}
void ft_look_at(t_pars *pars, t_params *params)
{
  t_obs obs;
  int color;
  float square_y;
  t_sprite sprite;

  obs.pix = 0;
  obs.line = 0;
  square_y = 0.;
  ft_background(pars, params);
  while (obs.pix < pars->width)
  {
    ft_distance_init(&obs, pars);
    ft_detect_obs(pars, &obs);
    obs.line = obs.draw_start;
    ft_side_pick(pars, &obs);
    if (obs.heigth_column_PJ > pars->height)
      square_y = ((float)(obs.heigth_column_PJ - pars->height)) / 2. * (64. / obs.heigth_column_PJ);
    else 
      square_y = 0;
    while (obs.line < obs.draw_end) 
    {
      color = ft_get_px_from_image(obs.text, obs.text_x, (int)square_y);
      square_y += 64. / obs.heigth_column_PJ;
      ft_put_px_in_image(&params->data, obs.pix, obs.line , color);
      obs.line++;
    }
    obs.pix++;
  }
  if (pars->is_a_sprite == 1)
  {
    printf("SPRITE PRINTED\n");
    ft_sprite_loop(pars, &sprite, params);
  }
  mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->data.img, 0, 0);
}

void  ft_put_px_in_image(t_data *data, int x, int y, int color)
{
  int pos = (y * data->size_line + x * data->bpp / 8) / sizeof(int);
  data->data[pos] = color;
}

int  ft_get_px_from_image(t_data *data, int x, int y)
{
  int pos = (y * data->size_line + x * data->bpp / 8) / sizeof(int);
  return(data->data[pos]);
}
