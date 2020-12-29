

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"

typedef struct      s_data
{
  void *img;
  unsigned int *data;
  int bpp;
  int size_line;
  int endian;
}                   t_data;

typedef struct        s_pars
{
  int width;
  int height;
  t_data text_n;
  void *text_s;
  void *text_w;
  void *text_e;
  void *text_sprite;
  int color_f;
  int color_c;
  char *map;
  float px;
  float py;
  float dx;
  float dy;
  float plane_x;
  float plane_y;
}                      t_pars;

typedef struct      s_params
{
  void *mlx_ptr;
  void *win_ptr;
  t_data data;
  int map_h;
  int map_w;
}                   t_params;

//typedef struct      s_size_map
//{
//}                   t_size_map;

typedef struct      s_obs
{
  float ox;
  float oy;
  int   dist;
  float dist_screen;
  double true_dist;
  float rayon_angle;
  int   heigth_wall;
  int   heigth_column_PJ;
  double raydir_x;
  double raydir_y;
  double camera;
  int   draw_start;
  int   draw_end;
  int   side;
  int   pix;
  int   map_x;
  int   map_y;
}                   t_obs;


void ft_resolution(t_params *params, char *elements, t_pars *pars);
void ft_text_n(t_params *params, char *elements, t_pars *pars);
void ft_text_s(t_params *params, char *elements, t_pars *pars);
void ft_text_w(t_params *params, char *elements, t_pars *pars);
void ft_text_e(t_params *params, char *elements, t_pars *pars);
void  ft_color(t_params *params, char *elements, t_pars *pars);
void  ft_putstr(char *str);
int   ft_space(char *elements);
void ft_map_save(t_params *params, char *elements, t_pars *pars);
void  ft_error(char *str);
void  ft_error_map(char *str, t_pars *pars);
void  ft_xpm_to_image(t_params params, char *elements, void **text);
void  ft_putchar(char c);
void  ft_putnbr(int n);
int  deal_key(int key, t_params params);
int  ft_identify_type(char c);
char			**ft_split_one(char *s, char c, t_params *params);
char **ft_global_map_check(t_pars *pars, t_params *params);
void  ft_direction(t_pars *pars, char c);
void  ft_location_player(t_pars *pars, char **map); 
void ft_look_at(t_pars pars, t_params params, char **map);
// void  ft_put_image(t_params params, t_pars pars);
void  ft_put_px_in_image(t_data *data, int x, int y, int color);

#endif
