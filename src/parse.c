/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:19:19 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/05 17:53:01 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        list_to_array(t_list *list, char **array)
{
    int     height;
    int     width;
    int     width_line;
    t_list  *ptr;

    ptr = list;
    height = ft_lstsize(list);
    while (ptr != NULL)
    {
        width_line = ft_strlen(list->content);
        width = width_line > width ? width_line : width;
        ptr = ptr->next;
    }
   *array = malloc(width * height);
}

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

void        populate_input(t_data_cub *data)
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

void        process_input(t_data_cub *data)
{
    populate_input(data);
    // list_to_array(data->input.map, data->input.map_array);
    // validate_input(data);
}