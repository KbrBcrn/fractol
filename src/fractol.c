/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:03:43 by jboumal           #+#    #+#             */
/*   Updated: 2022/10/12 09:57:36 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_image(t_fractol *b)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;

	b->img = mlx_new_image(b->mlx, WIDTH, HEIGHT);
	if (!b->img)
	{
		mlx_destroy_window(b->mlx, b->win);
		free(b->mlx);
		free(b);
		exit(EXIT_FAILURE);
	}
	buffer = mlx_get_data_addr(b->img, &pixel_bits, &line_bytes, &endian);
	b->buffer = buffer;
}

void	init(t_fractol *f, char fract)
{
	f->min_r = -1;
	f->max_r = 1;
	f->min_i = -1.0 * HEIGHT / WIDTH;
	f->max_i = 1.0 * HEIGHT / WIDTH;
	f->fractal = fract;
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		free(f);
		exit(EXIT_FAILURE);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
	{
		free(f->mlx);
		free(f);
		exit(EXIT_FAILURE);
	}
	init_image(f);
	f->cr = 0;
	f->ci = 0;
	f->color = 0;
	f->dynamic = 1;
	set_color(f);
	draw_fractal(f);
}

int	main(int argc, char **argv)
{
	t_fractol	*f;
	char		fract;
	int			dynamic;

	dynamic = 1;
	if (argc == 1 || argc >= 4)
		return (quit());
	if (argc >= 2)
		fract = parse_fractal(argv[1]);
	f = malloc(sizeof (t_fractol));
	if (!f)
		return (0);
	init(f, fract);
	if (argc == 3)
		f->dynamic = ft_atoi(argv[2]);
	mlx_key_hook(f->win, deal_key, f);
	mlx_hook(f->win, 17, 0L, destroy_window, f);
	mlx_mouse_hook(f->win, mouse_button, f);
	if (f->fractal == 'J')
		mlx_hook(f->win, 6, 0L, change_julia, f);
	mlx_loop(f->mlx);
	destroy_all(f);
	return (0);
}
