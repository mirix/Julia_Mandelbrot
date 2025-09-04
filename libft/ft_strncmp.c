/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:40:07 by emoman            #+#    #+#             */
/*   Updated: 2025/06/18 17:10:38 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)str1;
	us2 = (const unsigned char *)str2;
	if (!n)
		return (0);
	while (n > 0 && *us1 && *us1 == *us2)
	{
		us1++;
		us2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*us1 - *us2);
}
