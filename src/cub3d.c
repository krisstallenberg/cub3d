/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 19:13:23 by kris          #+#    #+#                 */
/*   Updated: 2020/10/14 12:29:47 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
    process_input(&data);
    start_game(&data);
    test_shit(&data);                   // TESTING
    free(data.input.map_array);
    exit(0);
}
