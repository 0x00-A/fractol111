/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:26:30 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/21 00:18:35 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_get_max_iter(t_data *data, double x, double y)
{
	double	a;
	double	b;
	double	tmp;
	int		i;

	a = data->re_s + (x / (double)WIDTH) * (data->re_e - data->re_s);
	b = data->im_e - (y / (double)HEIGHT) * (data->im_e - data->im_s);
	i = 0;
	while (ft_cabs(a, b) < 4 && i < MAX_ITERATIONS)
	{
		tmp = a;
		a = pow(a, 2) - pow(b, 2) + data->mouse.x;
		b = (2 * tmp * b) + data->mouse.y;
		i++;
	}
	return (i);
}

void	ft_draw_julia(t_data *data)
{
	int		max_iter;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			max_iter = ft_get_max_iter(data, x, y);
			my_mlx_pixel_put(data, x, y, ft_get_color(max_iter));
			x++;
		}
		y++;
	}
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
