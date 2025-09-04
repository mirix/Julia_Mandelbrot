/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:58:10 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 10:10:03 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n)
{
	int		count;
	long	nl;
	char	c;

	count = 0;
	nl = (long)n;
	if (nl < 0)
	{
		write(1, "-", 1);
		nl = -nl;
		count += 1;
	}
	if (nl > 9)
		count += print_nbr((int)(nl / 10));
	c = (char)(nl % 10 + '0');
	write(1, &c, 1);
	count += 1;
	return (count);
}

int	print_unbr(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += print_unbr((int)(n / 10));
	c = (char)(n % 10 + '0');
	write(1, &c, 1);
	count += 1;
	return (count);
}

int	handle_int(va_list *args)
{
	int	i;

	i = va_arg(*args, int);
	return (print_nbr(i));
}

int	handle_uint(va_list *args)
{
	unsigned int	i;

	i = va_arg(*args, int);
	return (print_unbr(i));
}
