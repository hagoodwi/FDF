/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 00:23:14 by msybell           #+#    #+#             */
/*   Updated: 2020/02/15 23:11:50 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projections_keys(int key, t_fdf *fdf)
{
	if (key == 18)
	{
		fdf->angl->x_rot = -3.834442;
		fdf->angl->z_rot = -2.534443;
		fdf->angl->y_rot = -2.614443;
	}
	if (key == 19)
	{
		fdf->angl->x_rot = 0;
		fdf->angl->y_rot = 0;
		fdf->angl->z_rot = 0;
	}
	if (key == 20)
	{
		fdf->angl->x_rot = -3.14159265359 / 2;
		fdf->angl->y_rot = 0;
		fdf->angl->z_rot = 0;
	}
	if (key == 21)
	{
		fdf->angl->x_rot = -3.14159265359 / 2;
		fdf->angl->y_rot = -3.14159265359 / 2;
		fdf->angl->z_rot = 0;
	}
}

void	rotate_keys(int key, t_fdf *fdf)
{
	if (key == 2)
		fdf->angl->y_rot -= 0.0314159265359;
	if (key == 14)
		fdf->angl->z_rot += 0.0314159265359;
	if (key == 13)
		fdf->angl->x_rot -= 0.0314159265359;
	if (key == 0)
		fdf->angl->y_rot += 0.0314159265359;
	if (key == 12)
		fdf->angl->z_rot -= 0.0314159265359;
	if (key == 1)
		fdf->angl->x_rot += 0.0314159265359;
}

void	move_keys(int key, t_fdf *fdf)
{
	if (key == 126)
		fdf->delta_y -= 15;
	if (key == 125)
		fdf->delta_y += 15;
	if (key == 123)
		fdf->delta_x -= 15;
	if (key == 124)
		fdf->delta_x += 15;
}

void	zoom_keys(int key, t_fdf *fdf)
{
	if (key == 47 && fdf->zoom_z < 250)
		fdf->zoom_z *= 1.2;
	if (key == 43 && fdf->zoom_z > 0.1)
		fdf->zoom_z /= 1.2;
	if (key == 24 && fdf->zoom * fdf->width < 20000
		&& fdf->zoom * fdf->height < 20000 && fdf->zoom_z < 100)
	{
		fdf->zoom_z *= 1.2;
		fdf->zoom *= 1.2;
	}
	if (key == 27 && fdf->zoom * fdf->width > 500)
	{
		fdf->zoom_z /= 1.2;
		fdf->zoom /= 1.2;
	}
}

void	color_keys(int key, t_fdf *fdf)
{
	if (key == 23)
		fdf->color = 0xFF0000;
	if (key == 22)
		fdf->color = 0x00FF00;
	if (key == 26)
		fdf->color = 0x0000FF;
	if (key == 28)
		fdf->color = 0xFFFF00;
	if (key == 25)
		fdf->color = 0xFF00FF;
	if (key == 29)
		fdf->color = 0x00FFFF;
}
