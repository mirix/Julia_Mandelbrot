/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:09:13 by emoman            #+#    #+#             */
/*   Updated: 2025/09/02 10:00:00 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	timer_hook(t_data *d)
{
	int	is_animating;

	is_animating = d->shift_colors || (d->julia_d && d->julia_d->shift_colors);
	if (is_animating)
	{
		d->time += 0.02;
		if (d->shift_colors)
			redraw_image(d);
		if (d->julia_d && d->julia_d->shift_colors)
		{
			d->julia_d->time = d->time;
			redraw_image(d->julia_d);
		}
	}
	return (0);
}

int	mouse_motion_hook(int x, int y, t_data *d)
{
	static double	last_time;
	double			current_time;
	t_complex		pos;

	last_time = 0;
	current_time = clock() / (double)CLOCKS_PER_SEC;
	if (current_time - last_time < 0.1)
		return (0);
	last_time = current_time;
	pos = map(x, y, d);
	if (d->type == JULIA)
		ft_printf("Julia c = %f + %fi | z0 = %f + %fi                       \r",
			d->julia_c.x, d->julia_c.y, pos.x, pos.y);
	else
		ft_printf("Mandelbrot c = %f + %fi                                  \r",
			pos.x, pos.y);
	return (0);
}

static void	handle_zoom(int button, int x, int y, t_data *d)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (x - W / 2.0) * (3.5 / W) / d->zoom + d->offset_x;
	mouse_im = (y - H / 2.0) * (2.4 / H) / d->zoom + d->offset_y;
	if (button == 4)
		d->zoom *= ZOOM_FACTOR;
	else
		d->zoom /= ZOOM_FACTOR;
	if (d->zoom > MAX_ZOOM)
		d->zoom = MAX_ZOOM;
	d->offset_x = mouse_re - (x - W / 2.0) * (3.5 / W) / d->zoom;
	d->offset_y = mouse_im - (y - H / 2.0) * (2.4 / H) / d->zoom;
	d->depth = 50 + (int)(log10(d->zoom) * 20);
	if (d->depth > MAX_DEPTH)
		d->depth = MAX_DEPTH;
	d->needs_recompute = 1;
	draw_fractal(d);
}

int	mouse_hook(int button, int x, int y, t_data *d)
{
	t_complex	julia_param;

	if (button == 4 || button == 5)
		handle_zoom(button, x, y, d);
	else if (button == 1 && d->type == MANDELBROT)
	{
		julia_param = map(x, y, d);
		if (!isnan(julia_param.x) && !isnan(julia_param.y)
			&& !isinf(julia_param.x) && !isinf(julia_param.y))
			launch_julia_window(d, julia_param);
	}
	return (0);
}

int	close_hook(t_data *d)
{
	mlx_loop_end(d->mlx);
	return (0);
}
