/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:13:13 by emoman            #+#    #+#             */
/*   Updated: 2025/09/02 10:00:00 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	map(int px, int py, t_data *d)
{
	t_complex	z;

	z.x = (px - W / 2.0) * (3.5 / W) / d->zoom + d->offset_x;
	z.y = (py - H / 2.0) * (2.4 / H) / d->zoom + d->offset_y;
	return (z);
}

t_complex	apply_equation(t_complex z, t_complex c, t_data *d)
{
	t_complex	result;

	if (d->equation == Z_SQUARED)
	{
		result.x = z.x * z.x - z.y * z.y + c.x;
		result.y = 2.0 * z.x * z.y + c.y;
	}
	else if (d->equation == BURNING_SHIP)
	{
		result.x = z.x * z.x - z.y * z.y + c.x;
		result.y = 2.0 * fabs(z.x * z.y) + c.y;
	}
	else
	{
		result.x = z.x * z.x - z.y * z.y + c.x;
		result.y = -2.0 * z.x * z.y + c.y;
	}
	if (isnan(result.x) || isnan(result.y) || isinf(result.x)
		|| isinf(result.y))
	{
		result.x = 1000.0;
		result.y = 1000.0;
	}
	return (result);
}

void	*render_strip(void *arg)
{
	t_strip		*s;
	t_complex	pos;
	double		smooth_i;
	int			x;
	int			y;

	s = (t_strip *)arg;
	y = s->y0;
	while (y < s->y1)
	{
		x = 0;
		while (x < W)
		{
			pos = map(x, y, s->d);
			if (s->d->type == JULIA)
				smooth_i = iter_julia(pos, s->d->julia_c, s->depth, s->d);
			else
				smooth_i = iter_mandelbrot(pos, s->depth, s->d);
			s->d->iter[y * W + x] = smooth_i;
			x++;
		}
		y++;
	}
	return (NULL);
}

void	redraw_image(t_data *d)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			color = get_color(d->iter[y * W + x], d->depth, d);
			my_mlx_pixel_put(d, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	draw_fractal(t_data *d)
{
	if (d->needs_recompute)
	{
		threaded_render(d, d->depth);
		d->needs_recompute = 0;
	}
	redraw_image(d);
}
