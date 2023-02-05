/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:32:10 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/05 02:26:06 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	zoom(int button, int x, int y, t_data *data)
{
	double	zoom_factor = 1.1;

	// double x_ratio = (double)x / WINDOW_WIDTH;
	// double y_ratio = (double)y / WINDOW_HEIGHT;


	if (button == 4)
	{
		
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
	else if (button == 5)
	{
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
