#include "cub3d.h"

void  ft_detect_obs(t_pars *pars, t_obs *obs)
{
  float xa;
  float ya;
  float dist_x;
  float dist_y;
  int hit = 0;

  xa = fabs(1 / obs->raydir_x);
  ya = fabs(1 / obs->raydir_y);
  if (obs->raydir_x < 0)
  {
    obs->step_x = -1;
    dist_x = (pars->px - obs->map_x) * xa;
  }
  else
  {
    obs->step_x = 1;
    dist_x = (obs->map_x + 1.0 - pars->px) * xa; 
  }
  if (obs->raydir_y < 0)
  {
    obs->step_y = -1;
    dist_y = (pars->py - obs->map_y) * ya;
  }
  else
  {
    obs->step_y = 1;
    dist_y = (obs->map_y + 1.0 - pars->py) * ya; 
  }
  while (hit == 0)
  {
    if (dist_x < dist_y)
    {
      dist_x += xa;
      obs->map_x += obs->step_x;
      if (obs->step_x == 1)
        obs->side = 0;
      else if (obs->step_x == -1)
        obs->side = 1;
    }
    else 
    {
      dist_y += ya;
      obs->map_y += obs->step_y;
      if (obs->step_y == 1)
        obs->side = 2;
      else if (obs->step_y == -1)
        obs->side = 3;
    }
    if (pars->map[obs->map_y][obs->map_x] > '0')
      hit = 1;
  }
  if (obs->side == 0 || obs->side == 1)
    obs->true_dist = (obs->map_x - pars->px + (1 - obs->step_x) / 2) / obs->raydir_x;
  else 
    obs->true_dist = (obs->map_y - pars->py + (1 - obs->step_y) / 2) / obs->raydir_y;
}


void ft_distance_init(t_obs *obs, t_pars *pars)
{
  // int vision;
  obs->camera = (2. * obs->pix / (double)pars->width) - 1;
  obs->raydir_y = pars->dy + pars->plane_y * obs->camera;
  obs->raydir_x = pars->dx + pars->plane_x * obs->camera;
  obs->map_x = (int)pars->px;
  obs->map_y = (int)pars->py;
  obs->heigth_column_PJ = (int)(pars->height / obs->true_dist);
  obs->draw_start = (-obs->heigth_column_PJ / 2) + (pars->height / 2);
  obs->draw_end = (obs->heigth_column_PJ / 2) + (pars->height / 2);
  // printf("column: %d\n", obs->heigth_column_PJ);
  if (obs->draw_start < 0)
    obs->draw_start = 0;
  if (obs->draw_end >= pars->height)
    obs->draw_end = pars->height - 1;
  // printf("draw start: %d\n", obs->draw_start);
  // printf("draw end: %d\n", obs->draw_end);
}

void ft_apply_text_on_wall(t_pars *pars, t_obs *obs, t_data *text)
{
  double column_x;

  // obs->text_x = obs->pix;
  printf("obs->side =%d\n", obs->side);
  if (obs->side == 2 || obs->side == 3)
  {
    printf("PLOP\n");
    column_x = (double)pars->px + obs->true_dist * obs->raydir_x;
    printf("column in=%f\n", column_x);
  }
  else 
  {
    printf("TIC\n");
    column_x = (double)pars->py + obs->true_dist * obs->raydir_y;
    printf("column in=%f\n", column_x);
  }
  column_x -= (int)(column_x);
  printf("pars->py =%f\n", pars->py);
  printf("pars->px =%f\n", pars->px);
  printf("true dist =%f\n", obs->true_dist);
  printf("calcul =%f\n", (double)pars->px + obs->true_dist * obs->raydir_x);
  printf("raydir_x =%f\n", obs->raydir_x);
  printf("raydir_y =%f\n", obs->raydir_y);
  printf("column =%f\n", column_x);
  printf("text x in apply BEF =%d\n", obs->text_x);
  // if (pars->map[obs->map_y][obs->map_x] == '1')
  // {
    obs->text_x = (int)(column_x * (double)text->img_width);
    if ((obs->side == 0 || obs->side == 1) && obs->raydir_x > 0)
      obs->text_x = text->img_width - obs->text_x - 1;
    if ((obs->side == 2 || obs->side == 3) && obs->raydir_y < 0)
      obs->text_x = text->img_width - obs->text_x - 1;
    printf("text x in apply =%d\n", obs->text_x);
  // }
}

void   ft_side_pick(t_pars *pars, t_obs *obs)
{
  if (obs->side == 1)
  {
    obs->text = &pars->text_w;
    // printf("1 = W\n");
  }
  if (obs->side == 3)
  {
    obs->text = &pars->text_e;
    // printf("3 = E\n");
  }
  if (obs->side == 0)
  {
    obs->text = &pars->text_n;
    // printf("0 = N\n");
  }
  if (obs->side == 2)
  {
    obs->text = &pars->text_s;
    // printf("2 = S\n");
  }
  // if (obs->text_x == 0 || obs->text_x == obs->text->img_width)
  ft_apply_text_on_wall(pars, obs, obs->text);
}

void ft_look_at(t_pars *pars, t_params *params)
{
  t_obs obs;
  // int vision;

  int middle_screen = pars->height /2;

  int y2 = 0;
  float square_y = 0.;
  float square_x = 0.;
  float f = 0.0;
  while (f < pars->width) {
    y2 = 0;
    while (y2 < pars->height / 2) {
      ft_put_px_in_image(&params->data, f, middle_screen + y2 , pars->color_c);
      ft_put_px_in_image(&params->data, f, middle_screen - y2 , pars->color_f);
      y2++;
    }
    f += 1;
  }
  obs.pix = 0;
  int color;
  // if (obs.draw_start == 0)
  //   square_y = (obs.draw_start + ((obs.heigth_column_PJ - pars->height) / 2));
  while (obs.pix < pars->width)
  {
    ft_distance_init(&obs, pars);
    ft_detect_obs(pars, &obs);
    y2 = obs.draw_start;
    // square_x = 0.;
    // if (obs.draw_start == 0)
    // square_y = (obs.draw_start + ((obs.heigth_column_PJ - pars->height) / 2));
    ft_side_pick(pars, &obs);
    square_x = 0 + obs.text_x;
    printf("text x = %d\n", obs.text_x);
    if (obs.heigth_column_PJ > pars->height) {
      square_y = ((float)(obs.heigth_column_PJ - pars->height)) / 2. * (64. / obs.heigth_column_PJ);
    }
    else {
      square_y = 0;
    }
    // square_y = 0;
    // else 
    //   square_y = y2;
    printf("square_y: %f\n", square_y);
    // square_x = 0.;
    while (y2 < obs.draw_end) 
    {
      // printf("square_y vs pars text: %f vs %d\n", square_y, pars->text_n.img_height);
      // printf("pix : %d\n", obs.pix);
      // color = 0xf2f2f2;
      // printf("side : %d\n", obs.side);
      color = ft_get_px_from_image(obs.text, (int)square_x, (int)square_y);
      square_y += 64. / obs.heigth_column_PJ;
      // if (square_x ==  obs.text->img_width)
      //   ft_apply_text_on_wall(pars, &obs, obs.text);
      // // if (obs.side == 3)
      // {
      //   color = ft_get_px_from_image(&pars->text_e, (int)square_x, (int)square_y);
      //   square_y += 64. / obs.heigth_column_PJ;
      // }
      // if (obs.side == 0)
      // {
      //   color = ft_get_px_from_image(&pars->text_n, (int)square_x, (int)square_y);
      //   square_y += 64. / obs.heigth_column_PJ;
      // }
      // if (obs.side == 2)
      // {
      //   color = ft_get_px_from_image(&pars->text_s, (int)square_x, (int)square_y);
      //   square_y += 64. / obs.heigth_column_PJ;
      ft_put_px_in_image(&params->data, obs.pix, y2 , color);
      y2++;
    }
    // printf("pix vs pars text: %d vs %d\n", obs.pix, pars->text_n.img_width);
    // printf("square x vs pars text: %f vs %d\n", square_x, pars->text_n.img_width);
    // square_x += pars->text_n.img_width / 64.; 
    // obs.text_x += 64. / pars->text_n.img_width; 
    obs.pix++;
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
  // void  ft_put_image(t_params params, t_pars pars)
  // {
  //   t_data data;
  //   // int pos;
  //   int x;
  //   int y;
  // unsigned int *mlx_data_addr;

  // data.img = mlx_new_image(params.mlx_ptr, pars.width, pars.height);
  // data.data = (unsigned int *)mlx_get_data_addr(data.img, &data.bpp, &data.size_line, &data.endian);
  // y = 0;
  // while (y <pars.height) {
  //   x = 0;
  //   while(x<pars.width) {
  //     ft_put_px_in_image(&data, x,y, 0xFFFFFF);
  //     ++x;
  //   }
  //   ++y;
  // }
  // x= 50;
  // y=60;
  //     ft_put_px_in_image(&data, x,y, 0xFF0000);
  //     ft_put_px_in_image(&data, x,y+1, 0xFF0000);
  //     ft_put_px_in_image(&data, x,y+2, 0xFF0000);
  //     ft_put_px_in_image(&data, x,y+3, 0xFF0000);
  //     ft_put_px_in_image(&data, x+1,y, 0xFF0000);
  //     ft_put_px_in_image(&data, x+2,y, 0xFF0000);
  //     ft_put_px_in_image(&data, x+3,y, 0xFF0000);


  // pos = (y * data.size_line + x * (data.bpp / 8));
  // ft_put_px_in_image(&data, x,y, 0xFFFFFF);
  // ft_put_px_in_image(&data, x+1,y, 0x0D4104);
  // ft_put_px_in_image(&data, x-1,y, 0x0D4104);
  // ft_put_px_in_image(&data, x,y-1, 0x0D4104);
  // ft_put_px_in_image(&data, x,y+1, 0x0D4104);
  // ft_put_px_in_image(&data, 5000,5000, 0x0D4104);
  // ft_memset(data.data, 205, data.size_line * pars.height);
  // mlx_data_addr = (unsigned int *)data.data;
  // while (pos < pars.width)
  // {
  //   data.data[pos * data.bpp] = 150;//0x0D4104;
  //   // mlx_data_addr[pos] = 0x0D4104;
  //   pos++;
  // }
  // mlx_put_image_to_window(params.mlx_ptr, params.win_ptr, data.img, 0, 0);
  // }
