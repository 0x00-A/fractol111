/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:29:31 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/21 00:13:44 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_data *data)
{
	double	scale;

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

int	mouse_hook(int button, int x, int y, t_data *data)
{
	double	a;
	double	b;

	// if (button == 1)
	// {
		a = data->re_s + (x / (double)WIDTH) * (data->re_e - data->re_s);
		b = data->im_e - (y / (double)HEIGHT) * (data->im_e - data->im_s);
		data->mouse.x = a;
		data->mouse.y = b;
	// }
	if (button == 4 || button == 5)
		zoom(button, a, b, data);
	return (0);
}
