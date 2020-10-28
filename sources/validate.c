/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/05 15:23:21 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/23 12:48:28 by kris          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		validate_resolution(t_data_cub *data)
{
	if (data->input.resolution[0] > 1920 || data->input.resolution[1] > 1080)
	{
	   ft_dprintf(1, "resolution has been reset from %d by %d to 1920 by 1080 \
		\n", data->input.resolution[0], data->input.resolution[1]);
		data->input.resolution[0] = 1920;
		data->input.resolution[1] = 1080;
	}
}

void		validate_colors(t_data_cub *data)
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
			exit_error("RGB values for ceiling must be between 0 and 255", \
			data);
}

void		validate_paths(t_data_cub *data)
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

void		check_start(t_data_cub *data, int count_start)
{
	if (count_start == 1)
		return ;
	if (count_start == 0)
		exit_error("no starting position specified in map", data);
	if (count_start > 1)
		exit_error("multiple starting positions specified in map", data);
}

void		find_start(t_data_cub *data)                        // validate
{
	int count_start;
	int x;
	int y;

	count_start = 0;
	x = 0;
	y = 0;
	while (*data->map.array[y] != '\0')
	{
		while(data->map.array[y][x] != '\0')
		{
			if (ft_strchr("NESW", data->map.array[y][x]))
			{
				count_start++;
				data->map.start_x = x;
				data->map.start_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	check_start(data, count_start);
}

int			flood_recursion(t_data_cub *data, char **array, int x, int y)
{
	printf ("current x: %d, y: %d\n", x, y);
	if (ft_memchr("1x", array[y][x], 2))
		return (1);
	if ((x == data->map.max_x - 1) || (y == data->map.max_y - 1) || \
		x <= 0 || y <= 0)
		return (0);
	if (ft_memchr("NESW02", array[y][x], 6))
		array[y][x] = 'x';
	if (ft_memchr(" ", array[y][x], 1))
		return (0);
	return (flood_recursion(data, array, x + 1, y) && \
		flood_recursion(data, array, x + 1, y - 1) && \
		flood_recursion(data, array, x + 1, y + 1) && \
		flood_recursion(data, array, x, y + 1) && \
		flood_recursion(data, array, x, y - 1) && \
		flood_recursion(data, array, x - 1, y + 1) && \
		flood_recursion(data, array, x - 1, y - 1) && \
		flood_recursion(data, array, x - 1, y));
}

char		**arrdup(t_data_cub *data)
{
	char	**new_array;
	int		i;
	int		width_line;

	i = 0;
	new_array = ft_memmalloc((data->map.max_y + 1) * sizeof(char *));
	while (i < data->map.max_y)
	{
		new_array[i] = ft_memmalloc(data->map.max_x + 1);
		width_line = ft_strlen(data->map.array[i]);
		ft_memcpy(new_array[i], data->map.array[i], width_line);
		i++;
	}
	new_array[i] = ft_memmalloc(data->map.max_x);
	return (new_array);
}

void		flood_fill(t_data_cub *data)
{
	char **array_duplicate;

	array_duplicate = arrdup(data);
	printf("x: %d, y: %d\nmax_x: %d, max_y %d\n", data->map.start_x, data->map.start_y, data->map.max_x, data->map.max_y);
	if (!flood_recursion(data, array_duplicate, data->map.start_x, data->map.start_y))
		exit_error("invalid map", data);
	print_map_array(array_duplicate);                   // testing
	free_map_array(array_duplicate);
}

void		check_chars_map(t_data_cub *data)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (data->map.array[y][x])
	{
		while (data->map.array[y][x] != '\0')
		{
			if (!ft_strchr("012NESW \0", data->map.array[y][x]))
			{
				printf("current char: %c, x: %d, y: %d", data->map.array[y][x], x, y);
				exit_error("invalid chars found in map", data);
			}
			x++;
		}
		y++;
		x = 0;
	}
}

void		validate_map(t_data_cub *data)
{
	check_chars_map(data);
	find_start(data);
	flood_fill(data);
}

void		validate_input(t_data_cub *data)
{
	validate_resolution(data);
	validate_colors(data);
	validate_paths(data);
	validate_map(data);
}
