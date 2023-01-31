/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:28:27 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/29 19:37:49 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_rec{
	int x;
	int y;
	int width;
	int	hight;
}	t_rec;

typedef struct s_cir
{
	int x;
	int y;
	int radius;
}	t_cir;

void	ft_draw_rec(t_data *data, t_rec rec)
{
	int i;
	int j;

	if (data->win_ptr == NULL)
		return;
	rec.x -= rec.width / 2;
	rec.y -= rec.hight / 2;
	
	i = rec.y;
	while (i < rec.y + rec.hight)
	{
		j = rec.x;
		while (j < rec.x + rec.width)
		{
			if ((i == rec.y || i == rec.y + rec.hight - 1 ) || (j == rec.x || j == rec.x + rec.width - 1))
				my_mlx_pixel_put(data, j, i, RED_PIXEL);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void	ft_draw_complex_plan(t_data *data)
{
	int	i = 0, j;
	double	a;
	double	b;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			a = -2 + (j / (double)WINDOW_WIDTH) * 4;
			b = -2 + (i / (double)WINDOW_HEIGHT) * 4;
			// if (a == 0 || b == 0)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, ft_color_gradient(3, 100));
			// if (i == WINDOW_HEIGHT / 2 || j == WINDOW_WIDTH / 2)
			// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, RED_PIXEL);
			j++;
		}
		i++;
	}
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, 100, 100, RED_PIXEL);
}

int	ft_cal_distance(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	ft_draw_circle(t_data *data, t_cir cir)
{
	int i = 0, j;
	while (i < 300)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			if (ft_cal_distance(cir.x, cir.y, j, i) == cir.radius)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, j, i, RED_PIXEL);
			j++;
		}
		i++;
	}
}
