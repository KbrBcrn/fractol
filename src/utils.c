/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:00:21 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/07 13:30:46 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_all(t_fractol *bounds)
{
	mlx_destroy_image(bounds->mlx, bounds->img);
	mlx_destroy_window(bounds->mlx, bounds->win);
	free(bounds->mlx);
	free(bounds);
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

void	zoom(t_fractol *bounds, double zoom_size)
{
	double	width;
	double	height;

	width = bounds->max_r - bounds->min_r;
	height = bounds->max_i - bounds->min_i;
	bounds->min_r = bounds->min_r + (width - zoom_size * width) / 2;
	bounds->max_r = bounds->min_r + zoom_size * width;
	bounds->min_i = bounds->min_i + (height - zoom_size * height) / 2;
	bounds->max_i = bounds->min_i + zoom_size * height;
}

void	move(t_fractol *bounds, char dir, double size)
{
	double	width;
	double	height;

	width = bounds->max_r - bounds->min_r;
	height = bounds->max_i - bounds->min_i;
	if (dir == 'R')
	{
		bounds->min_r += width * size;
		bounds->max_r += width * size;
	}
	else if (dir == 'L')
	{
		bounds->min_r -= width * size;
		bounds->max_r -= width * size;
	}
	else if (dir == 'D')
	{
		bounds->min_i += height * size;
		bounds->max_i += height * size;
	}
	else if (dir == 'U')
	{
		bounds->min_i -= height * size;
		bounds->max_i -= height * size;
	}
}
