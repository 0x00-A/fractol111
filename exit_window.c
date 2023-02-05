/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:27:55 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/05 01:06:48 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handel_escape(int key, t_data *data)
{
	double scale;
	
	scale = 0.1;
	if (key == 53)
		window_close(data);
	if (key == 126)
	{
		data->im_s += scale;
		data->im_e += scale;
	}
	if (key == 125)
	{
		data->im_s -= scale;
		data->im_e -= scale;
	}
	if (key == 123)
	{
		data->re_s -= scale;
		data->re_e -= scale;
	}
	if (key == 124)
	{
		data->re_s += scale;
		data->re_e += scale;
	}
	return (0);
}

// int	handel_keyrelease(int key, t_data	*data)
// {
// 	(void)data;
// 	printf("keyrelease %d\n", key);
// 	return (0);
// }

int	window_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	exit (0);
}
