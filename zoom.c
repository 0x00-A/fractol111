/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:32:10 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/05 00:49:58 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int zoom(int button, int x, int y, t_data *data)
{
    double zoom_factor = 1.1;

	// double x_ratio = (double)x / WINDOW_WIDTH;
	// double y_ratio = (double)y / WINDOW_HEIGHT;


    if (button == 4) {
		
        // data->zoom *= zoom_factor;
        data->re_s += x;
        data->re_e += x;
        data->im_s += y;
        data->im_e += y;
        data->re_s *= zoom_factor;
        data->re_e *= zoom_factor;
        data->im_s *= zoom_factor;
        data->im_e *= zoom_factor;
    }
    else if (button == 5) {
        // data->zoom /= zoom_factor;
        data->re_s += x;
        data->re_e += x;
        data->im_s += y;
        data->im_e += y;
        data->re_s /= zoom_factor;
        data->re_e /= zoom_factor;
        data->im_s /= zoom_factor;
        data->im_e /= zoom_factor;
    }
    render(data);
    return 0;
}

int mouse_hook(int button, int x, int y, t_data *data)
{
	double	a;
	double	b;

	if (button == 1)
	{
		a = data->re_s + (x / (double)WIDTH) * (data->re_e - data->re_s);
		b = data->im_e - (y / (double)HEIGHT) * (data->im_e - data->im_s);
		data->mouse.x = a;
		data->mouse.y = b;
	}
	if (button == 4 || button == 5)
		zoom(button, a, b, data);
	// render(data);
	return (0);
}
