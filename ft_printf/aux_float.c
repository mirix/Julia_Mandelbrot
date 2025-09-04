/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:11:26 by emoman            #+#    #+#             */
/*   Updated: 2025/09/03 10:13:17 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	round_to_precision(double n, int precision)
{
	double	multiplier;
	int		i;

	multiplier = 1.0;
	i = 0;
	while (i < precision)
	{
		multiplier *= 10.0;
		i++;
	}
	return ((long long)(n * multiplier + 0.5) / multiplier);
}

static int	print_float_int_part(long int_part)
{
	int		count;
	char	c;

	count = 0;
	if (int_part >= 10)
		count += print_float_int_part(int_part / 10);
	c = (char)(int_part % 10 + '0');
	write(1, &c, 1);
	return (count + 1);
}

static int	print_float_frac_part(double frac_part, int precision)
{
	int		i;
	char	digit;

	i = 0;
	while (i < precision)
	{
		frac_part *= 10.0;
		digit = (char)((int)frac_part % 10 + '0');
		write(1, &digit, 1);
		frac_part -= (int)frac_part;
		i++;
	}
	return (precision);
}

int	print_float(double n)
{
	int		count;
	long	int_part;
	double	frac_part;

	count = 0;
	if (n < 0.0)
	{
		write(1, "-", 1);
		count++;
		n = -n;
	}
	n = round_to_precision(n, 15);
	int_part = (long)n;
	frac_part = n - (double)int_part;
	count += print_float_int_part(int_part);
	write(1, ".", 1);
	count++;
	count += print_float_frac_part(frac_part, 15);
	return (count);
}

int	handle_float(va_list *args)
{
	double	f;

	f = va_arg(*args, double);
	return (print_float(f));
}
