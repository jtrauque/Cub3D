/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:13:14 by jtrauque          #+#    #+#             */
/*   Updated: 2021/01/16 12:30:03 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H
# include "cub3d.h"

typedef struct s_pixel				t_pixel;
struct __attribute__((__packed__))	s_pixel
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};

typedef struct s_file_header		t_file_header;
struct __attribute__((__packed__))	s_file_header
{
	char			signature[2];
	unsigned int	sizeinbytes;
	unsigned int	reserved;
	unsigned int	pixel_data;
};

typedef struct s_info_header		t_info_header;
struct __attribute__((__packed__))	s_info_header
{
	unsigned int		header_size;
	int					width;
	int					height;
	unsigned short int	nmb_color_planes;
	unsigned short int	color_depth;
	unsigned int		compression;
	unsigned int		image_size;
	int					horizontal_resolution;
	int					vertical_resolution;
	unsigned int		color_table;
	unsigned int		important_colors;
};

#endif
