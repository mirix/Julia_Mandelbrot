/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:53:17 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 10:10:20 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s++, 1);
		count++;
	}
	return (count);
}

int	handle_str(va_list *args)
{
	char	*s;

	s = va_arg(*args, char *);
	return (print_str(s));
}
