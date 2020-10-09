/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 15:23:21 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/09 19:05:00 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        validate_resolution(t_data_cub *data)
{
    if (data->input.resolution[0] > 1920 || data->input.resolution[1] > 1080)
    {
       ft_dprintf(1, "resolution has been reset from %d by %d to 1920 by 1080 \
        \n", data->input.resolution[0], data->input.resolution[1]);
        data->input.resolution[0] = 1920;
        data->input.resolution[1] = 1080;
    }
}

void        validate_colors(t_data_cub *data)
{
    if (data->input.color[COL_F][0] < 0 || data->input.color[COL_F][0] > 255 \
        || data->input.color[COL_F][1] < 0 \
        || data->input.color[COL_F][1] > 255 \
        || data->input.color[COL_F][2] < 0 \
        || data->input.color[COL_F][2] > 255)
            exit_error("RGB values for floor must be between 0 and 255", data);
    if (data->input.color[COL_C][0] < 0 || data->input.color[COL_C][0] > 255 \
        || data->input.color[COL_C][1] < 0 \
        || data->input.color[COL_C][1] > 255 \
        || data->input.color[COL_C][2] < 0 \
        || data->input.color[COL_C][2] > 255)
            exit_error("RGB values for ceiling must be between 0 and 255", data);
}

void        validate_paths(t_data_cub *data)
{
    int i;

    i = 0;
    while (i < 5)
    {
        if (!ft_strend(data->input.textures[i], ".png"))
            exit_error("textures must have .png file extension", data);
        i++;
    }
    i = 0;
    while (i < 5)
    {
        data->input.tex_fd[i] = open(data->input.textures[i], O_RDONLY);
        if (data->input.tex_fd[i] == -1)
            exit_error("texture path cannot be opened", data);
        i++;
    }
}

void        find_start(t_data_cub *data)                        // validate
{
    int count_start;
    int x;
    int y;

    x = 0;
    y = 0;
    count_start = 0;
    while (*data->map.array[y] != '\0')
    {
        x = 0;
        while(data->map.array[y][x] != '\0')
        {
            if (ft_strchr("NESW", data->map.array[y][x]))
            {
                count_start++;
                data->map.start_x = x;
                data->map.start_y = y;
                printf("-----%d, %d\n", data->map.start_y, data->map.start_x);
            }
            printf("x = %d, y = %d, char = '%c'\n", x, y, data->map.array[y][x]);
            x++;
        }
        // if (!data->map.array[y][x])
        //     break ;
        x = 0;
        y++;
    }
}

void        validate_map(t_data_cub *data)
{
    find_start(data);
    printf("start position: x = %d, y = %d\n", data->map.start_x, data->map.start_y);
    // flood_fill(data);
}

void        validate_input(t_data_cub *data)
{
    validate_resolution(data);
    validate_colors(data);
    validate_paths(data);
    validate_map(data);
}
