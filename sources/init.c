/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:19:55 by kstallen      #+#    #+#                 */
/*   Updated: 2020/11/11 17:23:43 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_data_input(t_data_input *input)
{
	input->resolution[0] = -1;
	input->resolution[1] = -1;
	input->color[COL_F][0] = -1;
	input->color[COL_F][1] = -1;
	input->color[COL_F][2] = -1;
	input->color[COL_C][0] = -1;
	input->color[COL_C][1] = -1;
	input->color[COL_C][2] = -1;
	input->textures[TEX_NO] = NULL;
	input->textures[TEX_SO] = NULL;
	input->textures[TEX_EA] = NULL;
	input->textures[TEX_WE] = NULL;
	input->textures[TEX_S] = NULL;
	input->map = NULL;
	input->map_array = NULL;
}

void		init_data_map(t_data_map *map)
{
	map->array = NULL;
	map->start_x = 0;
	map->start_y = 0;
	map->max_x = 0;
	map->max_y = 0;
}

void		init_data_game(t_data_game *game)
{
	game->dir_x = 0;
	game->dir_y = 0;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->old_time = 0;
	game->time = 0;
	game->plane_x = 0;
	game->plane_y = 0;
}

void		init_data(t_data_cub *data)
{
	init_data_input(&data->input);
	init_data_map(&data->map);
	init_data_game(&data->game);
}