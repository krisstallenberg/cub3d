/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 10:52:59 by kstallen      #+#    #+#                 */
/*   Updated: 2019/12/03 10:53:02 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	size_t	count;
	t_list	*element;

	count = 0;
	element = lst;
	while (element != NULL)
	{
		count++;
		element = element->next;
	}
	return (count);
}
