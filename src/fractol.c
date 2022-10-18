/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:06:49 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/12 10:06:53 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* init_img:
*	Initializes an MLX image 
*/

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
	buffer = mlx_get_data_addr(b->img, &pixel_bits, &line_bytes, &endian); // get the memory address off image
	b->buffer = buffer;
}

void	init(t_fractol *f, char fract)
{
	f->min_r = -2;
	f->max_r = 1;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	f->fractal = fract;
	f->mlx = mlx_init(); // This will establish a connection to the correct graphical system 
			    // and will return a void * which holds the location of our current MLX instance. 
	if (!f->mlx)
	{
		free(f);
		exit(EXIT_FAILURE);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol"); // mlx_new_window function, which will return a pointer 
								  // to the window we have just created.
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
	if (argc == 1 || argc >= 4) // if no parameter is provided or if the parameter is invalid,
				    // the program displays a list of available parameters and exits properly. 
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
