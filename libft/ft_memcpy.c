/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:19:20 by emoman            #+#    #+#             */
/*   Updated: 2025/06/17 11:59:55 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned const char	*src_ptr;

	dest_ptr = dest_str;
	src_ptr = src_str;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest_str);
}
