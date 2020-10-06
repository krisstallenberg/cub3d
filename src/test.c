/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:23:22 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/06 15:32:10 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        test_shit(t_data_cub *data)
{
    // int i = 1;
    system("echo '\n-----LEAKS RAPPORT-----\n'; leaks cub3D");          // TESTING
    print_data(data);
    printf("Elem populated:\t%s\n", elements_are_populated(data) ? "yes" : "no");                         // TESTING
    // while (i < 9)
    // {
    //     printf("Element %d is populated: %d\n", i, elem_is_populated(data, i));
    //     i++;
    // }
}

void    print_data(t_data_cub *data)
{
    print_data_input(&data->input);
}

void    print_map(t_list *map)
{
    t_list  *ptr;

    ptr = map;
    printf("map:");
    {
        while (ptr != NULL)
        {
            printf("\t\t[%s]\n", ptr->content);
            ptr = ptr->next;
        }
    }
}

void    print_map_array(t_data_input *input)
{
    int y;

    y = 0;
    printf("map_array:\n");
    // printf("\t\t[%c]\n", *input->map_array[y]);
    if (input->map_array == NULL)
        printf("hurray\n");

    while (input->map_array[y] != NULL)
    {
        printf("\t\t[%s]\n", input->map_array[y]);
        y++;
    }
}

void    print_data_input(t_data_input *input)
{
    printf("\n-----INPUT DATA-----\n\n");
    printf("fd:\t\t[%d]\n", input->fd);
    printf("line:\t\t[%s]\n", input->line);
    printf("resolution:\t[%d] [%d]\n", input->resolution[0], input->resolution[1]);
    printf("floor color:\t[%d] [%d] [%d]\n", input->color[COL_F][0], \
    input->color[COL_F][1], input->color[COL_F][2]);
    printf("ceiling color:\t[%d] [%d] [%d]\n", input->color[COL_C][0], \
    input->color[COL_C][1], input->color[COL_C][2]);
    printf("north texture:\t[%s]\n", input->textures[TEX_NO]);
    printf("east texture:\t[%s]\n", input->textures[TEX_EA]);
    printf("south texture:\t[%s]\n", input->textures[TEX_SO]);
    printf("west texture:\t[%s]\n", input->textures[TEX_WE]);
    printf("sprite texture:\t[%s]\n", input->textures[TEX_S]);
    // print_map(input->map);
    print_map_array(input);
}