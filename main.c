/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 02:20:14 by aigounad          #+#    #+#             */
/*   Updated: 2023/02/04 23:45:20 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int	render(t_data *data)
{
	(void)data;
	// ft_draw_complex_plan(data);
	// ft_draw_rec(data, (t_rec){WIDTH / 2, HEIGHT / 2, 100, 50});
	// ft_draw_circle(data, (t_cir){WIDTH / 2, HEIGHT / 2, 60});
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

void	ft_print_options(void)
{
	printf("Not enough or invalid args\n");
	printf("Usage: <./fractol> <fractal_name>\n");
	printf("Available fractals: Mandelbrot Julia\n");
	printf("Note: julia set can have a third paramiter for generating different sets [1-3]\n");
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_cplan_limits(t_data *data)
{
	data->re_s = RE_START;
	data->re_e = RE_END;
	data->im_s = IM_START;
	data->im_e = IM_END;
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
	if (ac == 3)
		data.fractal.julia_opt = av[2];
	else
		data.fractal.julia_opt = 0;
	ft_cplan_limits(&data);
	if (makewindow(&data) == 1)
		return (1);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, 2, 0, handel_escape, &data);
	mlx_hook(data.win_ptr, 17, 0, window_close, &data);
	// mlx_hook(data.win_ptr, 4, 0, zoom, &data);
	mlx_mouse_hook(data.win_ptr, mouse_hook, &data);
	mlx_loop(data.mlx_ptr);
}
