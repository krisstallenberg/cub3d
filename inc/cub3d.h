/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kris <kris@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 19:22:19 by kris          #+#    #+#                 */
/*   Updated: 2020/10/01 17:00:37 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"
#define E_R 1
#define E_NO 2
#define E_SO 3
#define E_EA 4
#define E_WE 5
#define E_S 6
#define E_F 7
#define E_C 8
#define E_M 9
#define TEX_NO 0
#define TEX_SO 1
#define TEX_EA 2
#define TEX_WE 3
#define TEX_S 4
#define COL_F 0
#define COL_C 1

typedef struct      s_map
{
    char            *line;
    struct s_map    *next;
}                   t_map;

typedef struct      s_data_input
{
    int             fd;
    char            *line;
    int             resolution[2];
    int             color[2][3];
    t_map           *map;
    char            *textures[5];
}                   t_data_input;

typedef struct      s_data_cub
{
    int             screenshot;
    t_data_input    input;
}                   t_data_cub;

int     main(int argc, char *argv[]);
void    exit_error(char *error_msg, t_data_cub *data);
void    read_input(t_data_cub *data);
void    parse_line(t_data_cub *data);