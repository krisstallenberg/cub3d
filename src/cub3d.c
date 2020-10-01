/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 19:13:23 by kris          #+#    #+#                 */
/*   Updated: 2020/09/23 14:58:35 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_data_input(t_data_input *input)
{
    printf("\n-----INPUT DATA-----\n\n");
    printf("fd:\t\t%d\n", input->fd);
    printf("line:\t\t%s\n", input->line);
    printf("resolution:\t%d %d\n", input->resolution[0], input->resolution[1]);
    printf("floor color:\t%d %d %d\n", input->color[COL_F][0], \
    input->color[COL_F][1], input->color[COL_F][2]);
    printf("ceiling color:\t%d %d %d\n", input->color[COL_C][0], \
    input->color[COL_C][1], input->color[COL_C][2]);
    printf("north texture:\t%s\n", input->textures[TEX_NO]);
    printf("east texture:\t%s\n", input->textures[TEX_EA]);
    printf("south texture:\t%s\n", input->textures[TEX_SO]);
    printf("west texture:\t%s\n", input->textures[TEX_WE]);
    printf("sprite texture:\t%s\n", input->textures[TEX_S]);
}

void    print_data(t_data_cub *data)
{
    print_data_input(&data->input);
}

int     check_elem_type(char *line)
{
    if (line[0] == 'R' && line[1] == ' ')
        return (E_R);
    if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        return (E_NO);
    if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        return (E_SO);
    if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        return (E_WE);
    if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        return (E_EA);
    if (line[0] == 'S' && line[1] == ' ')
        return (E_S);
    if (line[0] == 'F' && line[1] == ' ')
        return (E_F);
    if (line[0] == 'C' && line[1] == ' ')
        return (E_C);
    if (line[0] == 'R' && line[1] == ' ')
        return (E_R);
    if (line[0] == '1')
        return (E_M);
    if (line[0] == '\0')
       return (0);
    else 
        return (-1);
}

int     elem_is_populated(t_data_cub *data, int elem_type)
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

void        populate_elem(t_data_cub *data, int elem_type)
{
    if (elem_type == E_R)
        populate_resolution(data);
    if (elem_type >= E_NO && elem_type <= E_S)
        populate_texture(data, elem_type);
    if (elem_type == E_F || elem_type == E_C)
        populate_color(data, elem_type);
}

void        parse_line(t_data_cub *data)
{
    int     elem_type;

    elem_type = check_elem_type(data->input.line);
    if (elem_is_populated(data, elem_type))
        exit_error("Unable to redefine input element", data);
    if (elem_type)
        populate_elem(data, elem_type);
}

void        read_input(t_data_cub *data)
{
    int     ret;

    ret = 1;
    while (get_next_line(data->input.fd, &data->input.line) == 1)
    {
        printf("[%s]\n", data->input.line);                                // testing
        parse_line(data);
        free(data->input.line);
    }
    if (data->input.line)
    {
        printf("[%s]\n", data->input.line);                                // testing
        parse_line(data);
        free(data->input.line);
    }
}

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
}

void        init_data(t_data_cub *data)
{
    init_data_input(&data->input);
}

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

int         main(int argc, char *argv[])
{
    t_data_cub  data;

    data.screenshot = (argc == 3 && !ft_strncmp(argv[2], "--save", 7));
    if (argc != (2 + data.screenshot))
        exit_error("False amount of parameters", &data);
    if (!ft_strend(argv[1], ".cub"))
        exit_error("Wrong file extension", &data);
    data.input.fd = open(argv[1], O_RDONLY);
    if (data.input.fd == -1)
        exit_error("", &data);
    init_data(&data);
    read_input(&data);
    test_shit(&data);                   // TESTING
    exit(0);
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
}

void        free_data(t_data_cub *data)
{
    free_data_input(&data->input);
}

/*
**      Prints error message [1], frees all data [2] and exits with code 1.
**      [1] Prints error_msg if provided, defaults to perror otherwise.
**      [2] Freeing is done in free_struct().
*/

void        exit_error(char *error_msg, t_data_cub *data)
{
    if (*error_msg)
        ft_fprintf(2, "Error: %s\n", error_msg);
    else
        perror("Error");
    free_data(data);
    exit(1);
}
