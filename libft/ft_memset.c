/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:43:45 by emoman            #+#    #+#             */
/*   Updated: 2025/06/17 12:00:44 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*ptr;

	uc = c;
	ptr = str;
	while (n > 0)
	{
		n--;
		ptr[n] = uc;
	}
	return (str);
}
