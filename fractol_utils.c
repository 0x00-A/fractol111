/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:27:55 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/05 02:23:46 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_cplan_limits(t_data *data)
{
	data->re_s = RE_START;
	data->re_e = RE_END;
	data->im_s = IM_START;
	data->im_e = IM_END;
}

void	ft_print_options(void)
{
	printf("Not enough or invalid args\n");
	printf("Usage: <./fractol> <fractal_name>\n");
	printf("Available fractals: Mandelbrot Julia burningship\n");
}
