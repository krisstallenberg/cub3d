/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:19:55 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/01 20:14:57 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        init_data_input(t_data_input *input)
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
    // input->map->next = NULL;
}

void        init_data(t_data_cub *data)
{
    init_data_input(&data->input);
}