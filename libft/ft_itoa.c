/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:47:06 by emoman            #+#    #+#             */
/*   Updated: 2025/06/18 14:17:00 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	check_length(long long n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long long	val;

	val = (long long)n;
	len = check_length(val);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (val == 0)
		str[0] = '0';
	if (val < 0)
	{
		str[0] = '-';
		val = -val;
	}
	str[len] = '\0';
	while (val != 0)
	{
		str[len - 1] = (val % 10) + '0';
		val /= 10;
		len--;
	}
	return (str);
}
