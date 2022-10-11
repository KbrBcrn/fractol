/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:00:34 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/07 13:00:36 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/* set_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)

static void	set_pixel_color(t_fractol *b, int x, int y, int color)
{
	b->buffer[x * 4 + WIDTH * y * 4] = color;
	b->buffer[x * 4 + WIDTH * y * 4 + 1] = color >> 8;
	b->buffer[x * 4 + WIDTH * y * 4 + 2] = color >> 16;
	b->buffer[x * 4 + WIDTH * y * 4 + 3] = color >> 24;
}

void	draw_fractal(t_fractol *b)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			cr = b->min_r + ((double)x / WIDTH) * (b->max_r - b->min_r);
			ci = b->min_i + ((double)y / HEIGHT) * (b->max_i - b->min_i);
			add_pixel(b, x, y, b->color_set[fractal(b, cr, ci)]);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(b->mlx, b->win, b->img, 0, 0);
}
