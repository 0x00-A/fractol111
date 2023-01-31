/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:32:10 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/31 19:29:28 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button,int x, int y, t_data *data)
{
    double zoom_factor = 0.6;

	x = data->offset.re_start + (x / (double)WINDOW_WIDTH) * (data->offset.re_end - data->offset.re_start);
	y = data->offset.im_start + (y / (double)WINDOW_HEIGHT) * (data->offset.im_end - data->offset.im_start);
	// return (0);
	// double x_ratio = (double)x / WINDOW_WIDTH;
	// double y_ratio = (double)y / WINDOW_HEIGHT;


    if (button == 4) {
		
        // data->zoom *= zoom_factor;
        data->offset.re_start += x;
        data->offset.re_end += x;
        data->offset.im_start += y;
        data->offset.im_end += y;
        data->offset.re_start *= zoom_factor;
        data->offset.re_end *= zoom_factor;
        data->offset.im_start *= zoom_factor;
        data->offset.im_end *= zoom_factor;
    }
    else if (button == 5) {
        // data->zoom /= zoom_factor;
        data->offset.re_start += x;
        data->offset.re_end += x;
        data->offset.im_start += y;
        data->offset.im_end += y;
        data->offset.re_start /= zoom_factor;
        data->offset.re_end /= zoom_factor;
        data->offset.im_start /= zoom_factor;
        data->offset.im_end /= zoom_factor;
    }
    render(data);
    return 0;
}