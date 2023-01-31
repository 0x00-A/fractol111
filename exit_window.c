/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:27:55 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/30 20:40:31 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handel_escape(int key, t_data *data)
{
	(void)data;
	if (key == 110)
	{
		mlx_destroy_image(data->mlx_ptr, data->img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		// mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	return (0);
}

// int	handel_keyrelease(int key, t_data	*data)
// {
// 	(void)data;
// 	printf("keyrelease %d\n", key);
// 	return (0);
// }

int	window_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img);
	// mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	data->win_ptr = NULL;
	data->mlx_ptr = NULL;
	exit (0);
}
