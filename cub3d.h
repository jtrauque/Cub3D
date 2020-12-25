

#ifndef CUB3D_H
# define CUB3D_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"

typedef struct        s_pars
{
  int width;
  int height;
  void *text_n;
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
}                      t_pars;

typedef struct      s_params
{
  void *mlx_ptr;
  void *win_ptr;
}                   t_params;

//typedef struct      s_player
//{
//}                   t_player;

typedef struct      s_obs
{
  float ox;
  float oy;
}                   t_obs;

typedef struct      s_data
{
  void *img;
  void *data;
  int bpp;
  int size_line;
  int endian;
}                   t_data;

void ft_resolution(t_params params, char *elements, t_pars *pars);
void ft_text_n(t_params params, char *elements, t_pars *pars);
void ft_text_s(t_params params, char *elements, t_pars *pars);
void ft_text_w(t_params params, char *elements, t_pars *pars);
void ft_text_e(t_params params, char *elements, t_pars *pars);
void  ft_color(t_params params, char *elements, t_pars *pars);
void  ft_putstr(char *str);
int   ft_space(char *elements);
void ft_map_save(t_params params, char *elements, t_pars *pars);
void  ft_error(char *str);
void  ft_error_map(char *str, t_pars *pars);
void  ft_xpm_to_image(t_params params, char *elements, void **text);
void  ft_putchar(char c);
void  ft_putnbr(int n);
int  deal_key(int key, t_params params);
int  ft_identify_type(char c);

#endif
