/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: kstallen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 14:27:40 by kstallen      #+#    #+#                 */
/*   Updated: 2019/12/07 13:45:50 by kstallen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	if (alst == NULL)
		return ;
	last = ft_lstlast(*alst);
	if (last)
		last->next = new;
	else
		*alst = new;
}
