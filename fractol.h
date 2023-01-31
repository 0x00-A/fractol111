/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 03:22:00 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/31 18:09:03 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//includes
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
// # include <X11/keysym.h>
// # include <X11/X.h>
# include <math.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"


#define WINDOW_WIDTH 1620
#define WINDOW_HEIGHT 1080

#define	RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF
#define BLACK_PIXEL 0x000000

#define RE_START -4
#define RE_END 2
#define IM_START -2
#define IM_END 2
#define MAX_ITERATIONS 100

typedef struct s_fractal
{
	char	*name;
	char	*julia_opt;
}	t_fractal;

typedef struct s_offset{
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;

}	t_offset;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int zoom;
	t_offset offset;

	t_fractal fractal;
}	t_data;



void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_draw_mandelbrot(t_data *data);
double	ft_cabs(double re, double im);
int		ft_get_color(int iterations);
int		makewindow(t_data *data);
int		window_close(t_data *data);
int		handel_escape(int key, t_data *data);
int mouse_hook(int button,int x, int y, t_data *data);
// int mouse_hook(int button,double x, double y, t_data *data);

int	render(t_data *data);


void	ft_print_options(void);

int		ft_get_color(int iterations);
int		ft_color_gradient(int iterations, int max_iterations);

void	ft_draw_complex_plan(t_data *data);
#endif