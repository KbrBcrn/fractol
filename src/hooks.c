/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:38:39 by jboumal           #+#    #+#             */
/*   Updated: 2022/10/12 09:47:33 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy_window(void *param)
{
	t_fractol	*f;

	f = param;
	destroy_all(f);
	exit(EXIT_SUCCESS);
}

static int	handle_key(int key, t_fractol *f)
{
	if (key == 69 || key == 24)
		zoom(f, 0.5);
	else if (key == 78 || key == 27)
		zoom(f, 2);
	else if (key == 124)
		move(f, 'R', 0.3);
	else if (key == 125)
		move(f, 'D', 0.3);
	else if (key == 123)
		move (f, 'L', 0.3);
	else if (key == 126)
		move (f, 'U', 0.3);
	else if (key == 37)
	{
		if (f->dynamic == 0)
			f->dynamic = 1;
		else
			f->dynamic = 0;
	}
	else
		return (0);
	return (1);
}

int	deal_key(int key, void *param)
{
	t_fractol	*f;

	f = param;
	if (key == 12)
		f->cr -= 0.1;
	else if (key == 13)
		f->cr += 0.1;
	else if (key == 31)
		f->ci -= 0.1;
	else if (key == 35)
		f->ci += 0.1;
	else if (key == 8)
	{
		f->color = (f->color + 1) % 5;
		set_color(f);
	}
	else if (key == 53)
	{
		destroy_all(f);
		exit(EXIT_SUCCESS);
	}
	else if (!handle_key(key, f))
		return (0);
	draw_fractal(f);
	return (0);
}

int	mouse_button(int key, int x, int y, void *param)
{
	t_fractol	*f;

	f = param;
	if (key == 4)
	{
		zoom(f, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, 'L', (double)-x / WIDTH);
		else if (x > 0)
			move(f, 'R', (double)x / WIDTH);
		if (y < 0)
			move(f, 'U', (double)-y / HEIGHT);
		else if (y > 0)
			move(f, 'D', (double)y / HEIGHT);
	}
	else if (key == 5)
		zoom(f, 2);
	draw_fractal(f);
	return (0);
}

int	change_julia(int x, int y, void *param)
{
	t_fractol	*f;

	f = param;
	if (f->dynamic)
	{
		f->cr = -1.5 + 2.5 * (double)x / WIDTH;
		f->ci = -1 + 2 * (double)y / HEIGHT;
		draw_fractal(f);
	}
	return (0);
}
