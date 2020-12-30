#include "cub3d.h"

void  ft_detect_obs(t_pars *pars, t_obs *obs)
{
  float xa;
  float ya;
  float dist_x;
  float dist_y;
  int step_x = 0;
  int step_y = 0;
  int hit = 0;

  // printf("obs->raydir_x : %f\n", obs->raydir_x);
  // printf("obs->raydir_y : %f\n", obs->raydir_y);
  // xa = sqrt(1 + (obs->raydir_y * obs->raydir_y) / (obs->raydir_x * obs->raydir_x));
  // ya = sqrt(1 + (obs->raydir_x * obs->raydir_x) / (obs->raydir_y * obs->raydir_y));
  xa = fabs(1 / obs->raydir_x);
  ya = fabs(1 / obs->raydir_y);
  // printf("xa : %f\n", xa);
  // printf("ya : %f\n", ya);
  // printf("x : %d\n", obs->map_x);
  // printf("y : %d\n", obs->map_y);
  if (obs->raydir_x < 0)
  {
    step_x = -1;
    // printf("step_x : %d\n", step_x);
    dist_x = (pars->px - obs->map_x) * xa;
    // printf("1 dist_x : %f\n", dist_x);
  }
  else
  {
    step_x = 1;
    dist_x = (obs->map_x + 1.0 - pars->px) * xa; 
    // printf("2 dist_x : %f\n", dist_x);
    // printf("2 pars.px : %f\n", pars.px);
    // printf("2 xa : %f\n", xa);
  }
  if (obs->raydir_y < 0)
  {
    step_y = -1;
    // printf("step_y : %d\n", step_y);
    dist_y = (pars->py - obs->map_y) * ya;
    // printf("3 dist_x : %f\n", dist_x);
    // printf("3 dist_y : %f\n", dist_y);
  }
  else
  {
    step_y = 1;
    // printf("step_y : %d\n", step_y);
    dist_y = (obs->map_y + 1.0 - pars->py) * ya; 
    // printf("4 dist_x : %f\n", dist_x);
    // printf("4 dist_y : %f\n", dist_y);
  }
  while (hit == 0)
  {
    // printf("PLOP\n");
    // printf("dist_x : %f\n", dist_x);
    // printf("dist_y : %f\n", dist_y);
    if (dist_x < dist_y)
    {
      dist_x += xa;
      obs->map_x += step_x;
      if (step_x == 1)
        obs->side = 0;
      else if (step_x == -1)
        obs->side = 1;
      // printf("step_x : %d\n", step_x);
    }
    else 
    {
      dist_y += ya;
      obs->map_y += step_y;
      if (step_y == 1)
        obs->side = 2;
      else if (step_y == -1)
        obs->side = 3;
      // printf("step_y : %d\n", step_y);
    }
    if (pars->map[obs->map_y][obs->map_x] == '1')
      hit = 1;
  }
  if (obs->side == 0 || obs->side == 1)
    obs->true_dist = (obs->map_x - pars->px + (1 - step_x) / 2) / obs->raydir_x;
  else 
    obs->true_dist = (obs->map_y - pars->py + (1 - step_y) / 2) / obs->raydir_y;
  // printf("obs.ox : %f\n", obs->ox);
  // printf("obs.oy : %f\n", obs->oy);
  // printf("ture dist : %f\n", obs->true_dist);
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
void ft_look_at(t_pars *pars, t_params *params)
{
  t_obs obs;
  // int vision;

  int middle_screen = pars->height /2;

  int y2 = 0;
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
  while (obs.pix < pars->width) {
    ft_distance_init(&obs, pars);
    ft_detect_obs(pars, &obs);
    y2 = obs.draw_start;
    // printf("side : %d\n", obs.side);
    while (y2 < obs.draw_end) 
    {
      color = 0xf2f2f2;
      if (obs.side == 1 || obs.side == 3)
        color = 0xCCCCCC;
      ft_put_px_in_image(&params->data, obs.pix, y2 , color);
      y2++;
    }
    obs.pix++;
  }
  mlx_put_image_to_window(params->mlx_ptr, params->win_ptr, params->data.img, 0, 0);
}


/*
   void  ft_floor_casting(int dist, int dist_screen, int vision, t_pars pars)
   {
   int wall_bottom;
   int n;

   wall_bottom = dist / dist_screen;
   n = vision / (pj_height - vision);

   }*/

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
