/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:21:07 by emoman            #+#    #+#             */
/*   Updated: 2025/09/04 15:21:09 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	smooth_iteration(t_complex z, int i)
{
	double	log_zn;
	double	nu;

	if (isnan(z.x) || isnan(z.y) || isinf(z.x) || isinf(z.y))
		return ((double)i);
	log_zn = log(z.x * z.x + z.y * z.y) / 2.0;
	if (log_zn < 1e-10)
		return ((double)i);
	nu = log(log_zn / log(2.0)) / log(2.0);
	return ((double)i + 1.0 - nu);
}

double	iter_julia(t_complex z0, t_complex c, int depth, t_data *d)
{
	t_complex	z;
	int			i;
	double		magnitude;

	z = z0;
	i = 0;
	while (i < depth)
	{
		magnitude = z.x * z.x + z.y * z.y;
		if (magnitude > 4.0 || isnan(magnitude) || isinf(magnitude))
			break ;
		z = apply_equation(z, c, d);
		i++;
	}
	if (i == depth)
		return ((double)depth);
	return (smooth_iteration(z, i));
}

double	iter_mandelbrot(t_complex c, int depth, t_data *d)
{
	t_complex	z;
	int			i;
	double		magnitude;

	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i < depth)
	{
		magnitude = z.x * z.x + z.y * z.y;
		if (magnitude > 4.0 || isnan(magnitude) || isinf(magnitude))
			break ;
		z = apply_equation(z, c, d);
		i++;
	}
	if (i == depth)
		return ((double)depth);
	return (smooth_iteration(z, i));
}
