/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:19:26 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/21 00:16:39 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_cabs(double re, double im)
{
	return (pow(re, 2) + pow(im, 2));
}

int	ft_get_max_iter(double re, double im)
{
	double	z_re;
	double	z_im;
	double	temp;
	int		max_iter;

	z_re = re;
	z_im = im;
	max_iter = 0;
	while (ft_cabs(z_re, z_im) < 4 && max_iter < MAX_ITERATIONS)
	{
		temp = z_re;
		z_re = (z_re * z_re) - (z_im * z_im) + re;
		z_im = 2 * temp * z_im + im;
		max_iter++;
	}
	return (max_iter);
}

void	ft_draw_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	a;
	double	b;
	int		max_iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			a = data->re_s + (x / (double)WIDTH) * (data->re_e - data->re_s);
			b = data->im_s + (y / (double)HEIGHT) * (data->im_e - data->im_s);
			max_iter = ft_get_max_iter(a, b);
			my_mlx_pixel_put(data, x, y, ft_get_color(max_iter));
			x++;
		}
		y++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
