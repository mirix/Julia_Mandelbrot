/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:13:40 by emoman            #+#    #+#             */
/*   Updated: 2025/06/19 12:54:21 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nnodes;

	if (!lst)
		return (0);
	nnodes = 0;
	while (lst)
	{
		nnodes++;
		lst = lst->next;
	}
	return (nnodes);
}
