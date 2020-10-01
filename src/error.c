/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <kstallen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 18:21:43 by kstallen      #+#    #+#                 */
/*   Updated: 2020/10/01 18:22:08 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
