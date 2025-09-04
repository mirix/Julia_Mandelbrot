/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:00:00 by emoman            #+#    #+#             */
/*   Updated: 2025/09/02 10:00:00 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	build_title(char *dst, t_data *d)
{
	const char	*prefix;
	int			i;

	if (d->type == JULIA)
		prefix = "Julia Set - ";
	else
		prefix = "Mandelbrot Set";
	i = 0;
	while (prefix[i] && i < 255)
	{
		dst[i] = prefix[i];
		i++;
	}
	if (d->type == JULIA)
		append_julia_info(dst, &i, d);
	dst[i] = '\0';
}

static double	parse_fraction(const char *str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	while (*str && ft_isdigit(*str))
	{
		fraction += (*str - '0') / divisor;
		divisor *= 10.0;
		str++;
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;

	result = 0.0;
	sign = 1.0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		result += parse_fraction(str);
	}
	return (result * sign);
}

int	is_valid_double(const char *str)
{
	int	has_digit;
	int	has_dot;

	has_digit = 0;
	has_dot = 0;
	if (!str)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			has_digit = 1;
		else if (*str == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		str++;
	}
	return (has_digit);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
