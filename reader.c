/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:49:50 by hagoodwi          #+#    #+#             */
/*   Updated: 2020/02/21 19:21:46 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		height_width_fdf(int fd, t_fdf *fdf)
{
	char	*str;
	int		height;
	int		width;
	int		width_check;

	height = 0;
	width = 0;
	width_check = 0;
	while (get_next_line(fd, &str))
	{
		height++;
		width_check = (int)ft_numbofword(str, ' ');
		if (width == 0)
			width = width_check;
		else if (width_check != width)
			exit(1);
		if (width == 0)
			exit(1);
		free(str);
	}
	if (height == 0 || width == 0)
		exit(1);
	fdf->height = height;
	fdf->width = width;
	close(fd);
}

void		matrix_fdf(char *str, int *matrix)
{
	char	**ch_matrix;
	int		i;

	if (!(ch_matrix = ft_strsplit(str, ' ')))
		exit(1);
	i = 0;
	while (ch_matrix[i])
	{
		matrix[i] = atoi(ch_matrix[i]);
		free(ch_matrix[i]);
		i++;
	}
	free(ch_matrix);
}

void		check_folder_open(char *filename)
{
	int		fd0;

	fd0 = open(filename, O_RDONLY);
	if (read(fd0, NULL, 0) == -1)
		exit(1);
	close(fd0);
}

void		reader(char *filename, t_fdf *fdf)
{
	int		fd;
	char	*str;
	int		i;

	check_folder_open(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 3)
		exit(1);
	height_width_fdf(fd, fdf);
	if (!(fdf->matrix = malloc(sizeof(int*) * fdf->height)))
		exit(1);
	i = 0;
	while (i < fdf->height)
		if (!(fdf->matrix[i++] = malloc(sizeof(int) * fdf->width)))
			exit(1);
	i = 0;
	str = NULL;
	fd = open(filename, O_RDONLY);
	while ((1 == get_next_line(fd, &str)))
	{
		matrix_fdf(str, fdf->matrix[i]);
		free(str);
		i++;
	}
	close(fd);
}
