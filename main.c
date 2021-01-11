/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:40:57 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/02/15 22:19:09 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			close_window(void)
{
	exit(0);
	return (0);
}

int			press_key(int key, t_fdf *fdf)
{
	color_keys(key, fdf);
	projections_keys(key, fdf);
	rotate_keys(key, fdf);
	move_keys(key, fdf);
	zoom_keys(key, fdf);
	if (key == 53)
		close_window();
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	draw(fdf);
	return (0);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (1);
	fdf = initialization(argv[1]);
	draw(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, press_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 1L << 17, close_window, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
