/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 22:21:45 by msybell           #+#    #+#             */
/*   Updated: 2020/02/15 23:09:46 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calc_zoom(t_fdf *fdf)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = WIDTH_WINDOW / (fdf->width * 2);
	zoom_y = HEIGHT_WINDOW / (fdf->height * 2);
	fdf->zoom = zoom_x < zoom_y ? zoom_x : zoom_y;
}

t_fdf		*initialization(char *filename)
{
	t_fdf	*fdf;

	if (!(fdf = malloc(sizeof(*fdf))))
		exit(1);
	reader(filename, fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
								WIDTH_WINDOW, HEIGHT_WINDOW, "FDF");
	calc_zoom(fdf);
	fdf->zoom_z = 5;
	fdf->delta_x = WIDTH_WINDOW / 2;
	fdf->delta_y = HEIGHT_WINDOW / 2;
	fdf->angl = malloc(sizeof(t_angles));
	fdf->angl->x_rot = -3.834442;
	fdf->angl->z_rot = -2.534443;
	fdf->angl->y_rot = -2.614443;
	fdf->color = 0xFF0000;
	return (fdf);
}
