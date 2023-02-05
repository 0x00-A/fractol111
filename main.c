/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:20:14 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/05 02:06:46 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_data *data)
{
	if (!strncmp(data->fractal.name, "mandelbrot", 11))
		ft_draw_mandelbrot(data);
	else if (!strncmp(data->fractal.name, "julia", 5))
		ft_draw_julia(data);
	else if (!strncmp(data->fractal.name, "burningship", 5))
		ft_draw_burningship(data);
	else
	{
		ft_print_options();
		window_close(data);
	}
	return (0);
}

void	fun()
{
	system("leaks fractol");
}

int	main(int ac, char **av)
{
	atexit(fun);
	t_data	data;

	data.zoom = 1;

	if (ac < 2)
	{
		ft_print_options();
		exit(1);
	}
	data.fractal.name = av[1];
	ft_cplan_limits(&data);
	if (makewindow(&data) == 1)
		return (1);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 0, key_hook, &data);
	mlx_hook(data.win_ptr, 17, 0, window_close, &data);
	// mlx_hook(data.win_ptr, 4, 0, zoom, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
}
