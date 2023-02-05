/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:40:10 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/05 02:09:24 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_get_max_iter(double	x, double y)
{
	double	re;
	double	im;
	double	tmp;
	int		i;

	i = 0;
	re = x;
	im = y;
	while (ft_cabs(re, im) < 2 && i < MAX_ITERATIONS)
	{
		tmp = re;
		re = pow(fabs(re), 2) - pow(fabs(im), 2) + x;
		im = 2 * fabs(tmp) * fabs(im) + y;
		i++;
	}
	return (i);
}

void	ft_draw_burningship(t_data *data)
{
	int		x;
	int		y;
	double	re;
	double	im;
	int		max_iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			re = data->re_s + (x / (double)WIDTH) * (data->re_e - data->re_s);
			im = data->im_s + (y / (double)HEIGHT) * (data->im_e - data->im_s);
			max_iter = ft_get_max_iter(re, im);
			my_mlx_pixel_put(data, x, y, ft_get_color(max_iter));
			x++;
		}
		y++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
