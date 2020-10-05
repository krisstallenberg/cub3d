/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:19:19 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/05 10:53:33 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        parse_line(t_data_cub *data)
{
    int     elem_type;

    elem_type = check_elem_type(data->input.line, data);
    if (elem_is_populated(data, elem_type))
        exit_error("Unable to redefine input element", data);
    if (elem_type)
        populate_elem(data, elem_type);
    printf("[%s]\n", data->input.line);                                // testing
}

void        read_input(t_data_cub *data)
{
    int     ret;

    ret = 1;
    while (get_next_line(data->input.fd, &data->input.line) == 1)
    {
        parse_line(data);
        free(data->input.line);
    }
    if (data->input.line)
    {
        parse_line(data);
        free(data->input.line);
    }
}