/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:32:31 by emoman            #+#    #+#             */
/*   Updated: 2025/06/17 11:55:58 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void			*ptr;
	unsigned char	*bptr;
	size_t			total_size;

	if (nitems == 0 || size == 0)
	{
		ptr = malloc(1);
		if (ptr)
			*(unsigned char *)ptr = 0;
		return (ptr);
	}
	if (size && nitems > ((size_t)-1) / size)
		return (NULL);
	total_size = nitems * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	bptr = (unsigned char *)ptr;
	while (total_size--)
		*bptr++ = 0;
	return (ptr);
}
