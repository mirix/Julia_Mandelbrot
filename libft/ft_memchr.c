/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:28:43 by emoman            #+#    #+#             */
/*   Updated: 2025/06/17 11:59:03 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*s;

	s = (unsigned char *)str;
	uc = (unsigned char)c;
	while (n--)
	{
		if (*s == uc)
			return (s);
		s++;
	}
	return (NULL);
}
