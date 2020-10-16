/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:20:45 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/14 10:49:48 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        free_map_list(t_data_input *input)
{
    int i;
    t_list *ptr;

    i = 0;
    ptr = input->map;
    while (ptr != NULL)
    {
        free(ptr->content);
        ptr = ptr->next;

    }
}

void        free_map_array(char **array)
{
    int i;

    i = 0;
    while (*array[i] != '\0')
    {
        free(array[i]);
        array[i] = NULL;
        i++;
    }
    if (i > 0)
        free(array[i]);
    if (array != NULL)
    {
        free(array);
        array = NULL;
    }
}

void        free_data_input(t_data_input *input)
{
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
        free_map_list(input);
}

void    free_data_map(t_data_map *map)
{
    if (map->array)
        free_map_array(map->array);
}

void        free_data(t_data_cub *data)
{
    free_data_input(&data->input);
    free_data_map(&data->map);
}
