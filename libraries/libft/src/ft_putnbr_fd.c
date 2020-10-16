/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 13:17:43 by kstallen      #+#    #+#                 */
/*   Updated: 2019/11/25 13:17:44 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int s;

	s = 0;
	if (n >= 0)
		s = n;
	if (n < 0)
	{
		s = n * -1;
		ft_putchar_fd('-', fd);
	}
	if (s > 9)
		ft_putnbr_fd(s / 10, fd);
	ft_putchar_fd((s % 10) + '0', fd);
}
