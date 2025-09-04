/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_vptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:05:54 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 11:51:11 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_vptr(unsigned long long addr)
{
	char	buffer[18];
	int		count;
	int		i;

	i = 0;
	if (addr == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	i = hex_buffer(addr, buffer, i, 'p');
	buffer[i++] = 'x';
	buffer[i++] = '0';
	count = i;
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (count);
}

int	handle_vptr(va_list *args)
{
	unsigned long long	addr;

	addr = (unsigned long long)va_arg(*args, void *);
	return (print_vptr(addr));
}
