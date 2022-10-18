/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:06:23 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/12 10:06:27 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_all(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	free(f->mlx);
	free(f);
}

char	parse_fractal(char *s)
{
	if (ft_strncmp(s, "M", 2) == 0 || ft_strncmp(s, "m", 2) == 0)
		return ('M');
	else if (ft_strncmp(s, "J", 2) == 0 || ft_strncmp(s, "j", 2) == 0)
		return ('J');
	else if (ft_strncmp(s, "B", 2) == 0 || ft_strncmp(s, "b", 2) == 0)
		return ('B');
	else
	{
		quit();
		exit(EXIT_SUCCESS);
	}
}

int	quit(void)
{
	write (1, "Please provide the fractal that you want to display.\n", 54);
	write (1, "List of available fractals:\n", 29);
	write (1, "[M] Mandelbrot\n", 16);
	write (1, "[J] Julia\n", 11);
	write (1, "[B] Burning ships\n", 19);
	return (0);
}

/* zoom:
*	Zooms the view of the fractal in or out by adjusting
*	the complex number edge values by a zoom multiplier.
*	The fractal can then be generated again at a different resolution,
*	giving the appearance of zooming in or out.
*	If the zoom multiplier is small, like 0.5, the view will
*	zoom in, if it is big, like 2.0, it will zoom out.
*/

void	zoom(t_fractol *f, double zoom_size)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	f->min_r = f->min_r + (width - zoom_size * width) / 2;
	f->max_r = f->min_r + zoom_size * width;
	f->min_i = f->min_i + (height - zoom_size * height) / 2;
	f->max_i = f->min_i + zoom_size * height;
}

/* move:
*	Moves the view of the fractal by adjusting the complex
*	number edge values a certain distance in a certain direction.
*/

void	move(t_fractol *f, char dir, double size)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	if (dir == 'R')
	{
		f->min_r += width * size;
		f->max_r += width * size;
	}
	else if (dir == 'L')
	{
		f->min_r -= width * size;
		f->max_r -= width * size;
	}
	else if (dir == 'D')
	{
		f->min_i += height * size;
		f->max_i += height * size;
	}
	else if (dir == 'U')
	{
		f->min_i -= height * size;
		f->max_i -= height * size;
	}
}
