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

static void	add_pixel(t_fractol *b, int x, int y, int color)
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
