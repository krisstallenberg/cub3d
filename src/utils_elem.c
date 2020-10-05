/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_elem.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:25:29 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/05 16:07:09 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int elem_is_populated(t_data_cub *data, int elem_type)
{
    if (elem_type == E_R && data->input.resolution[0] != -1 \
        && data->input.resolution[0] != -1)
        return (1);
    else if (elem_type == E_NO && data->input.textures[TEX_NO] != NULL)
        return (1);
    else if (elem_type == E_SO && data->input.textures[TEX_SO] != NULL)
        return (1);
    else if (elem_type == E_WE && data->input.textures[TEX_WE] != NULL)
        return (1);
    else if (elem_type == E_EA && data->input.textures[TEX_EA] != NULL)
        return (1);
    else if (elem_type == E_S && data->input.textures[TEX_S] != NULL)
        return (1);
    else if (elem_type == E_F && data->input.color[COL_F][0] != -1 \
        && data->input.color[COL_F][1] != -1 \
        && data->input.color[COL_F][2] != -1)
        return (1);
    else if (elem_type == E_C && data->input.color[COL_C][0] != -1 \
        && data->input.color[COL_C][1] != -1 \
        && data->input.color[COL_C][2] != -1)
        return (1);
    else 
        return (0);
}

int elements_are_populated(t_data_cub* data)
{
    if (elem_is_populated(data, E_R) && \
        elem_is_populated(data, E_NO) && \
        elem_is_populated(data, E_SO) && \
        elem_is_populated(data, E_EA) && \
        elem_is_populated(data, E_WE) && \
        elem_is_populated(data, E_NO) && \
        elem_is_populated(data, E_S) && \
        elem_is_populated(data, E_F) && \
        elem_is_populated(data, E_C))
        return (1);
    else
        return (0);
}


int line_is_map(t_data_cub *data)
{
    static int  prev_line_map = 0;

    if (prev_line_map == -1)
        return (0);
    if (elements_are_populated(data) && !prev_line_map)
        while (*data->input.line != '\0')
        {
            if (*data->input.line == '1')
            {
                prev_line_map = 1;
                return (1);
            }
            data->input.line++;
        }
    if (prev_line_map && *data->input.line == '\0')
        prev_line_map = -1;
    else if (prev_line_map && *data->input.line != '\0')
        return (1);
    return (0);
}

int check_elem_type(char *line, t_data_cub *data)
{
    if (line[0] == 'R' && line[1] == ' ')
        return (E_R);
    else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        return (E_NO);
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        return (E_SO);
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        return (E_WE);
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        return (E_EA);
    else if (line[0] == 'S' && line[1] == ' ')
        return (E_S);
    else if (line[0] == 'F' && line[1] == ' ')
        return (E_F);
    else if (line[0] == 'C' && line[1] == ' ')
        return (E_C);
    else if (line[0] == 'R' && line[1] == ' ')
        return (E_R);
    else if (line_is_map(data))
        return (E_M);
    else if (line[0] == '\0')
       return (0);
    else 
        return (-1);
}
