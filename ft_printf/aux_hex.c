/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:01:57 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 10:01:59 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	hex_buffer(unsigned long long addr, char *buffer, int i, char format)
{
	unsigned long long	remainder;

	while (addr > 0 && i < 16)
	{
		remainder = addr % 16;
		if (remainder < 10)
			buffer[i] = remainder + '0';
		else
		{
			if (format == 'X')
				buffer[i] = 'A' + (remainder - 10);
			else
				buffer[i] = 'a' + (remainder - 10);
		}
		addr /= 16;
		i++;
	}
	return (i);
}

int	print_hex(unsigned long long addr, char format)
{
	char	buffer[16];
	int		count;
	int		i;

	i = 0;
	if (addr == 0)
		buffer[i++] = '0';
	i = hex_buffer(addr, buffer, i, format);
	count = i;
	while (i > 0)
		write(1, &buffer[--i], 1);
	return (count);
}

int	handle_hexl(va_list *args)
{
	unsigned long long	val;

	val = (unsigned long long)va_arg(*args, unsigned int);
	return (print_hex(val, 'x'));
}

int	handle_hexu(va_list *args)
{
	unsigned long long	val;

	val = (unsigned long long)va_arg(*args, unsigned int);
	return (print_hex(val, 'X'));
}
