/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbeceren <kbeceren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:01:38 by kbeceren          #+#    #+#             */
/*   Updated: 2022/10/07 13:31:20 by kbeceren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# define WIDTH 1000
# define HEIGHT 1200
# define MAX_ITER 80

typedef struct s_fractol
{
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	char	fractal;
	void	*mlx;
	void	*win;
	void	*img;
	char	*buffer;
	double	cr;
	double	ci;
	int		dynamic;
	int		color;
	int		color_set[MAX_ITER + 1];
}					t_fractol;

int		destroy_window(void *param);
int		deal_key(int key, void *param);
int		change_julia(int x, int y, void *param);
int		mouse_button(int key, int x, int y, void *param);

char	parse_fractal(char *s);
void	draw_fractal(t_fractol *b);
void	zoom(t_fractol *f, double zoom_size);
void	move(t_fractol *f, char dir, double size);
int		quit(void);
void	destroy_all(t_fractol *param);

void	set_pixel_color(t_fractol *f);
int		fractal(t_fractol *f, double cr, double ci);

#endif
