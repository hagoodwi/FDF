/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msybell <msybell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 00:19:10 by msybell           #+#    #+#             */
/*   Updated: 2020/02/14 00:19:12 by msybell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

float	max(float a, float b)
{
	return (a > b ? a : b);
}

float	mod(float i)
{
	return (i < 0 ? -i : i);
}

void	x_angle(float x, float *y, float *z, float angle)
{
	int	y2;
	int	z2;

	y2 = *y;
	z2 = *z;
	*y = y2 * cos(angle) + z2 * sin(angle);
	*z = -y2 * sin(angle) + z2 * cos(angle);
}

void	y_angle(float *x, float y, float *z, float angle)
{
	int	x2;
	int	z2;

	x2 = *x;
	z2 = *z;
	*x = x2 * cos(angle) + z2 * sin(angle);
	*z = -x2 * sin(angle) + z2 * cos(angle);
}

void	z_angle(float *x, float *y, float z, float angle)
{
	int	y2;
	int	x2;

	y2 = *y;
	x2 = *x;
	*x = x2 * cos(angle) - y2 * sin(angle);
	*y = x2 * sin(angle) + y2 * cos(angle);
}
