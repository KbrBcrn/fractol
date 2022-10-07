/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:00:46 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/07 13:00:49 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double zr, double zi, double cr, double ci)
{
	int		n;
	double	temp;

	n = 0;
	while (n < MAX_ITER && (zi * zi + zr * zr) <= 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		n++;
	}
	return (n);
}

int	burning_ship(double cr, double ci)
{
	int		n;
	double	zi;
	double	zr;
	double	temp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITER && (zi * zi + zr * zr) <= 4.0)
	{
		zr = fabs(zr);
		zi = fabs(zi);
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		n++;
	}
	return (n);
}

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zi;
	double	zr;
	double	temp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITER && (zi * zi + zr * zr) <= 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		n++;
	}
	return (n);
}

int	fractal(t_fractol *bounds, double cr, double ci)
{
	if (bounds->fractal == 'M')
		return (mandelbrot(cr, ci));
	if (bounds->fractal == 'B')
		return (burning_ship(cr, ci));
	else if (bounds->fractal == 'J')
		return (julia(cr, ci, bounds->cr, bounds->ci));
	return (0);
}
