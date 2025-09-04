/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:51:49 by emoman            #+#    #+#             */
/*   Updated: 2025/06/18 16:57:18 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	ch;

	len = 0;
	while (str[len])
		len++;
	ch = (char)c;
	if (ch == '\0')
		return ((char *)&str[len]);
	while (len > 0)
	{
		if (str[len - 1] == ch)
			return ((char *)&str[len - 1]);
		len--;
	}
	return (NULL);
}
