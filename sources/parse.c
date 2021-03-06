/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:19:19 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/14 10:20:42 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int         ft_lstwidth(t_list *list)
{
    int width;
    int line_width;

    width = 0;
    line_width = 0;

    while (list != NULL)
    {
        line_width = ft_strlen(list->content);
        width = line_width > width ? line_width : width;
        list = list->next;
    }
    return (width);
}

void        list_to_array(t_data_cub *data)
{
    int     width_line;
    t_list  *ptr;
    int     i;

    ptr = data->input.map;
    i = 0;
    data->map.max_y = ft_lstsize(ptr);
    data->map.max_x = ft_lstwidth(ptr);
    data->map.array = malloc((data->map.max_y + 1) * sizeof(char *));
    ptr = data->input.map;
    while (i < data->map.max_y)
    {
        data->map.array[i] = ft_memmalloc(data->map.max_x + 1);
        width_line = ft_strlen(ptr->content);
        ft_memcpy(data->map.array[i], ptr->content, width_line);
        ptr = ptr->next;
        i++;
    }
    data->map.array[data->map.max_y] = ft_memmalloc(data->map.max_x);
    free_map_list(&data->input); 
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
    list_to_array(data);
    validate_input(data);
}