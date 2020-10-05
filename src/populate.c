/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   populate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:18:25 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/05 15:15:34 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        populate_resolution(t_data_cub *data)
{
    int i;
    int dimension;

    i = 2;
    dimension = 0;
    while (data->input.line[i] != '\0')
    {
        if ((data->input.line[i] != ' ' && !ft_isdigit(data->input.line[i])) \
        || (ft_isdigit(data->input.line[i]) && dimension >= 2))
            exit_error("Invalid resolution specified", data);
        if (ft_isdigit(data->input.line[i]))
        {
            data->input.resolution[dimension] = ft_atoi(&data->input.line[i]);
            i += ft_numlen(data->input.resolution[dimension]);
            dimension++;
        }
        else
            i++;
    }
}

void        populate_color(t_data_cub *data, int elem_type)
{
    int i;
    int elem;
    int col;

    col = elem_type - 7;
    i = 2;
    elem = 0;
    while (data->input.line[i] != '\0')
    {
        if ((elem > 0 && elem < 3) && data->input.line[i] == ',')
            i++;
        if ((data->input.line[i] != ' ' && !ft_isdigit(data->input.line[i])) \
        || (ft_isdigit(data->input.line[i]) && elem >= 3))
            exit_error("Invalid color specified", data);
        if (ft_isdigit(data->input.line[i]))
        {
            data->input.color[col][elem] = ft_atoi(&data->input.line[i]);
            i += ft_numlen(data->input.color[col][elem]);
            elem++;
        }
        else
            i++;
    }
}

void        populate_texture(t_data_cub *data, int elem_type)
{
    int start;
    int len;
    int tex;

    tex = elem_type - 2;
    start = (elem_type == E_S) ? 1 : 2;
    len = 0;
    while (data->input.line[start] == ' ')
        start++;
    while (data->input.line[start + len] != ' ' \
        && data->input.line[start + len] != '\0')
        len++;
    data->input.textures[tex] = ft_substr(data->input.line, start, len);
    while (data->input.line[start + len] != '\0')
    {
        if (data->input.line[start + len] != ' ')
            exit_error("Invalid texture specified", data);
        len++;
    }
}

void        populate_map(t_data_cub *data)
{
    t_list  *temp;
    char    *line;

    line = ft_strdup(data->input.line);
    temp = ft_lstnew(line);
    ft_lstadd_back(&data->input.map, temp);
}

void        populate_elem(t_data_cub *data, int elem_type)
{
    if (elem_type == E_R)
        populate_resolution(data);
    if (elem_type >= E_NO && elem_type <= E_S)
        populate_texture(data, elem_type);
    if (elem_type == E_F || elem_type == E_C)
        populate_color(data, elem_type);
    if (elem_type == E_M)
        populate_map(data);
}