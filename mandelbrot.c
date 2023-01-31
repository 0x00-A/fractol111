/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:19:26 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/31 16:45:20 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_cabs(double re, double im)
{
	return (sqrt(pow(re, 2) + pow(im, 2)));
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
	while (ft_cabs(z_re, z_im) < 2 && max_iter < MAX_ITERATIONS)
	{
		temp = z_re;
		z_re = (z_re * z_re)  - (z_im * z_im) + re;
		z_im = 2 * temp * z_im + im;
		max_iter++;
	}
	return (max_iter);
}

void	ft_draw_mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int	max_iter;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			max_iter = ft_get_max_iter(data->offset.re_start + (x / (double)WINDOW_WIDTH) * (data->offset.re_end - data->offset.re_start),
					data->offset.im_start + (y / (double)WINDOW_HEIGHT) * (data->offset.im_end - data->offset.im_start));
			my_mlx_pixel_put(data, x, y, ft_get_color(max_iter));
			x++;
		}
		y++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
