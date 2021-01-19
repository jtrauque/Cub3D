/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:03:22 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/19 20:04:01 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "bmp.h"

# define GO_FORWARD 119
# define GO_BACKWARD 115
# define TURN_LEFT 97
# define TURN_RIGHT 100
# define GO_LEFT 113
# define GO_RIGHT 101

typedef struct	s_data
{
	void			*img;
	unsigned int	*data;
	int				bpp;
	int				size_line;
	int				endian;
	int				img_width;
	int				img_height;
}				t_data;

typedef struct	s_params
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	data;
	int		map_h;
	int		map_w;
}				t_params;

typedef struct	s_vecteur
{
	int x;
	int y;
}				t_vecteur;

typedef struct	s_pars
{
	t_params	*params;
	t_vecteur	*sprite;
	double		*buffer;
	int			count;
	int			width;
	int			height;
	char		**map;
//	t_data		text_s[1];
//	t_data		text_w[1];
//	t_data		text_e[1];
//	t_data		text_sprite[1];
	int			color_f;
	int			color_c;
	char		*map_tmp;
	double		px;
	double		py;
	double		dx;
	double		dy;
	double		plane_x;
	double		plane_y;
	int			sprite_nbr;
	int			is_a_sprite;
	int			is_a_sprite_x;
	int			is_a_sprite_y;
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			move_left;
	int			move_right;
	double		speed;
	int			save;
	t_data		text[5];
}				t_pars;

typedef struct	s_color
{
	int r;
	int g;
	int b;
}				t_color;

typedef struct	s_obs
{
	double	true_dist;
	double	sprite_true_dist;
	double	raydir_x;
	double	raydir_y;
	double	camera;
	int		heigth_column_pj;
	int		draw_start;
	int		draw_end;
	int		side;
	int		pix;
	int		line;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		text_x;
	double	dist_x;
	double	dist_y;
	double	xa;
	double	ya;
	t_data	*text;
}				t_obs;

typedef struct	s_sprite
{
	int		heigth_column;
	int		width_column;
	int		draw_start;
	int		draw_end;
	int		width_draw_start;
	int		width_draw_end;
	int		n;
	int		draw_x;
	int		draw_y;
	int		stripe;
	int		start;
	double	sprite_x;
	double	sprite_y;
	double	init;
	double	next_x;
	double	next_y;
	int		sprite_screen;
}				t_sprite;

int				ft_parsing(int fd, t_pars *pars, t_params *params);
int				ft_find_orientation(char c, char *str);
int				ft_resolution(t_params *params, char *elements, t_pars *pars);
int				ft_text(t_params *params, char *elements, t_pars *pars);
//int				ft_text_s(t_params *params, char *elements, t_pars *pars);
//int				ft_text_w(t_params *params, char *elements, t_pars *pars);
//int 			ft_text_e(t_params *params, char *elements, t_pars *pars);
int				ft_extract_text(char *elements, t_data *text, t_params *params);
char 			*ft_path(char *elements);
int				ft_color(t_params *params, char *elements, t_pars *pars);
void			ft_putstr(char *str);
int				ft_space(char *elements);
int				ft_space_and_plus(char *elements);
int				ft_map_save(t_params *params, char *elements, t_pars *pars);
int				ft_check_walls_column(t_pars *pars, t_params *params);
int				ft_check_column(t_pars *pars, t_params *params);
int				ft_check_walls(t_pars *pars, t_params *params);
int				ft_error(char *str);
void			*ft_error_map(char *str);
int				ft_free(t_params *params, t_pars *pars);
void			ft_xpm_to_image(t_params params, char *elements, void **text);
void			ft_putchar(char c);
void			ft_putnbr(int n);
int				deal_key(int key, t_pars *pars);
int				deal_key_release(int key, t_pars *pars);
int				ft_release(t_pars *pars);
void			ft_manage_mlx(t_params *params, t_pars *pars);
void			ft_manage_mlx_destroy(t_params *params, t_pars *pars);
int				ft_identify_type(char c);
char			**ft_split_one(char *s, char c, t_params *params);
char			**ft_global_map_check(t_pars *pars, t_params *params);
void			ft_direction(t_pars *pars, char c);
int				ft_location_player(t_pars *pars);
void			ft_look_at(t_pars *pars, t_params *params);
void			ft_put_px_in_image(t_data *data, int x, int y, int color);
void			ft_move(int key, t_pars *pars);
void			ft_side_move(t_pars *pars);
void			ft_rotate(t_pars *pars, float n);
void			ft_detect_obs(t_pars *pars, t_obs *obs);
void			ft_distance_init(t_obs *obs, t_pars *pars);
int				ft_get_px_from_image(t_data *data, int x, int y);
void			ft_put_px_in_image(t_data *data, int x, int y, int color);
void			ft_sprite_init(t_pars *pars, t_sprite *sprite);
void			ft_apply_text_on_wall(t_pars *pars, t_obs *obs, t_data *text);
void			ft_sprite_loop(t_pars *pars, t_sprite *sprite,
		t_params *params);
void			ft_sort_sprite(t_pars *pars);
int				ft_save_bmp(char *argv, t_pars *pars);
void			ft_create_bmp(t_pars *pars);

#endif
