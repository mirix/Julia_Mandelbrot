/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 15:46:20 by emoman            #+#    #+#             */
/*   Updated: 2025/06/18 17:25:12 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	llen;
	size_t	blen;
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	llen = ft_strlen(little);
	blen = ft_strlen(big);
	if (blen < llen || llen > len)
		return (NULL);
	i = 0;
	while (i + llen <= len)
	{
		j = 0;
		while (j < llen && big[i + j] == little[j])
			j++;
		if (j == llen)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
