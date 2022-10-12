/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:06:57 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/12 10:07:00 by kbeceren         ###   ########.fr       */
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

int	fractal(t_fractol *f, double cr, double ci)
{
	if (f->fractal == 'M')
		return (mandelbrot(cr, ci));
	if (f->fractal == 'B')
		return (burning_ship(cr, ci));
	else if (f->fractal == 'J')
		return (julia(cr, ci, f->cr, f->ci));
	return (0);
}
