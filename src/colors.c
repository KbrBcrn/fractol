/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:07:03 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/12 10:07:06 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_random_color(t_fractol *f)
{
	int	i;

	i = -1;
	while (++i <= MAX_ITER)
		f->color_set[i] = rand() % 16777215 // White;
	f->color_set[MAX_ITER] = 0;
}

void	set_mono_color(t_fractol *f, int r, int g, int b) // Monochromatic color is a color scheme made up of different forms of one color
{
	int	i;
	int	n;

	i = -1;
	while (++i <= MAX_ITER)
	{
		n = (i * 255 / (MAX_ITER)); // the amount of each primary color (red, green, and blue) is specified as a value from 0 to 255.
		f->color_set[i] = 0;
		if (b)
			f->color_set[i] += n;
		if (g)
			f->color_set[i] += 256 * n;
		if (r)
			f->color_set[i] += 256 * 256 * n;
	}
	f->color_set[MAX_ITER] = 0;
}

void	set_rainbow_color(t_fractol *f)
{
	int	i;
	int	n;

	i = -1;
	while (++i <= MAX_ITER)
	{
		n = 1535 - (i * 1535 / (MAX_ITER));
		if (n < 256)
			f->color_set[i] = 256 * 256 * 255 + n % 256;
		else if (n < 512)
			f->color_set[i] = 256 * 256 * (255 - (n % 256)) + 255;
		else if (n < 768)
			f->color_set[i] = 256 * (n % 256) + 255;
		else if (n < 1024)
			f->color_set[i] = 256 * 255 + (255 - (n % 256));
		else if (n < 1280)
			f->color_set[i] = 256 * 256 * (n % 256) + 256 * 255;
		else
			f->color_set[i] = 256 * 256 * 255 + 256 * (255 - (n % 256));
	}
	f->color_set[MAX_ITER] = 0;
}

void	set_shades_color(t_fractol *f, int color[4], int n)
{
	int	i;

	i = -1;
	while (++i <= MAX_ITER)
	{
		f->color_set[i] = color[i % n];
	}
	f->color_set[MAX_ITER] = 0;
}

void	set_color(t_fractol *f)
{
	int	color;

	color = f->color;
	if (color == 0)
		set_random_color(f);
	else if (color == 1)
		set_mono_color(f, 1, 1, 1);
	else if (color == 2)
		set_rainbow_color(f);
	else if (color == 3)
		set_mono_color(f, 0, 1, 1);
	else if (color == 4)
	{
		set_shades_color(f, (int [33]){0x4c4f3d, 0x586647, 0xada898,
			0x727760, 0x303425, 0xf7f4e8, 0x39462d, 0xdde3ca, 0x909e7c,
			0xa47a7c, 0xd6cbc2, 0x222d19, 0x1e2016, 0x93928c, 0x5b5b54,
			0x3b3b34, 0xbfc9ab, 0x6d5954, 0x8d8171, 0x7c9c6b, 0x6e474c,
			0x9f5f64, 0x131314, 0xe1acaf, 0x0b140a, 0x232424, 0x66333e,
			0x9c9c7c, 0x949c94, 0x481a23, 0x48642c, 0x6c3c34, 0x44241c}, 33);
	}
}
