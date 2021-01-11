/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:44:20 by msybell           #+#    #+#             */
/*   Updated: 2020/02/20 23:03:49 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		step_draw(t_point *p1, t_point *p2, t_fdf *fdf)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	maxx;

	x = p1->x;
	y = p1->y;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	maxx = max(mod(dx), mod(dy));
	dx /= maxx;
	dy /= maxx;
	while ((int)(p2->x - x) || (int)(p2->y - y))
	{
		if (!(x > WIDTH_WINDOW || x < 0 || y > HEIGHT_WINDOW || y < 0))
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
		x += dx;
		y += dy;
	}
	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color);
}

void		create_point(t_point *point, int x, int y, t_fdf *fdf)
{
	point->x = x * fdf->zoom;
	point->y = y * fdf->zoom;
	point->z = fdf->matrix[y][x];
	point->z *= fdf->zoom_z;
	point->x -= (fdf->width * fdf->zoom) / 2;
	point->y -= (fdf->height * fdf->zoom) / 2;
	x_angle(point->x, &(point->y), &(point->z), fdf->angl->x_rot);
	y_angle(&(point->x), point->y, &(point->z), fdf->angl->y_rot);
	z_angle(&(point->x), &(point->y), point->z, fdf->angl->z_rot);
	point->x += fdf->delta_x;
	point->y += fdf->delta_y;
}

void		draw_line(int x, int y, t_fdf *fdf)
{
	t_point	*p1;
	t_point	*p2;

	if (!(p1 = malloc(sizeof(t_point))))
		exit(1);
	create_point(p1, x, y, fdf);
	if (x < fdf->width - 1)
	{
		p2 = malloc(sizeof(t_point));
		create_point(p2, x + 1, y, fdf);
		step_draw(p1, p2, fdf);
		free(p2);
	}
	if (y < fdf->height - 1)
	{
		if (!(p2 = malloc(sizeof(t_point))))
			exit(1);
		create_point(p2, x, y + 1, fdf);
		step_draw(p1, p2, fdf);
		free(p2);
	}
	free(p1);
}

void		draw(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->height)
	{
		x = -1;
		while (++x < fdf->width)
			draw_line(x, y, fdf);
	}
}
