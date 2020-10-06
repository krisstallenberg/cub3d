/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:20:45 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 15:35:53 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        free_map(t_data_input *input)
{
    int i;
    t_list *ptr;

    i = 0;
    ptr = input->map;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = ptr->next;
    }
}

void        free_data_input(t_data_input *input)
{
    if (input->map)
        free(input->map);        // FREE ALL LINKED LIST NODES
    if (input->line)
        free(input->line);
    if (input->textures[TEX_NO])
        free(input->textures[TEX_NO]);
    if (input->textures[TEX_SO])
        free(input->textures[TEX_SO]);
    if (input->textures[TEX_EA])
        free(input->textures[TEX_EA]);
    if (input->textures[TEX_WE])
        free(input->textures[TEX_WE]);
    if (input->textures[TEX_S])
        free(input->textures[TEX_S]);
    if (input->map != NULL)
        free_map(input);
}

void        free_data(t_data_cub *data)
{
    free_data_input(&data->input);
}
