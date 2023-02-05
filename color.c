/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:22:53 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/04 18:50:33 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_get_color(int iterations)
{
	int	color;
	// unsigned int colors[10] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0x00FFFF,
    //                                 0xFF00FF, 0xC0C0C0, 0x808080, 0x404040, 0x000000};
	if (iterations == MAX_ITERATIONS)
		color = BLACK_PIXEL;
	// else if (iterations == 2)
	// 	color = RED_PIXEL;
	else
		// color = colors[iterations % 10];
		color = ft_color_gradient(iterations, MAX_ITERATIONS);
	return (color);
}

int	ft_color_gradient(int iterations, int max_iterations)
{
	int	r, g, b;
	double	t = (double)iterations / (double)max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int julia_color(int iterations, double value)
{
    int color;
	if (iterations == MAX_ITERATIONS)
		return (color = BLACK_PIXEL);
    double log_zn = log(value) / 2.0;
    double nu = log(log_zn / log(2)) / log(2);
    color = (int)(nu * 256) % 256;
    return (color | (color << 8) | (color << 16));
}