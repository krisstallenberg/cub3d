/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/14 16:46:30 by kstallen      #+#    #+#                 */
/*   Updated: 2020/11/17 16:42:19 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_data_cub *data)
{
	data->game.mlx = mlx_init();
	if (data->game.mlx == NULL)
		exit_error("mlx initialization failed", data);
	data->game.mlx_win = mlx_new_window(data->game.mlx, \
	data->input.resolution[0], data->input.resolution[1], "cub3D");
	
	mlx_loop(data->game.mlx);
	
	return ;
}
