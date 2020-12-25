#include "cub3d.h"

int  deal_key(int key, t_params params)
{
  (void) params;
  ft_putchar('X');
  ft_putnbr(key);
  if (key == 65307)
    exit(1);
//  mlx_pixel_put(params.mlx_ptr, params.mlx_ptr, 100, 100, 0x16A81D);
  return (0);
}

