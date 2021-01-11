/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:41:10 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/02/15 22:55:10 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# define WIDTH_WINDOW 1850
# define HEIGHT_WINDOW 1350

typedef struct
{
	float		x_rot;
	float		y_rot;
	float		z_rot;
}				t_angles;

typedef struct
{
	float		x;
	float		y;
	float		z;
}				t_point;

typedef struct
{
	int			width;
	int			height;
	int			**matrix;
	float		zoom;
	int			delta_x;
	int			delta_y;
	float		zoom_z;
	t_angles	*angl;
	void		*mlx_ptr;
	void		*win_ptr;
	int			color;
}				t_fdf;

void			reader(char *filename, t_fdf *fdf);
void			draw(t_fdf *fdf);
float			max(float a, float b);
float			mod(float i);
void			x_angle(float x, float *y, float *z, float angle);
void			y_angle(float *x, float y, float *z, float angle);
void			z_angle(float *x, float *y, float z, float angle);
t_fdf			*initialization(char *filename);
void			projections_keys(int key, t_fdf *fdf);
void			rotate_keys(int key, t_fdf *fdf);
void			move_keys(int key, t_fdf *fdf);
void			zoom_keys(int key, t_fdf *fdf);
void			color_keys(int key, t_fdf *fdf);

#endif
