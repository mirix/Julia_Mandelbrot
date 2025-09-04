/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:25:19 by emoman            #+#    #+#             */
/*   Updated: 2025/09/04 15:33:50 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_view(t_data *d)
{
	d->zoom = 1.0;
	if (d->type == MANDELBROT)
		d->offset_x = -0.75;
	else
		d->offset_x = 0.0;
	d->offset_y = 0.0;
	d->depth = 50;
}

static int	handle_param_keys(int keycode, t_data *d)
{
	if (keycode == 114)
		reset_view(d);
	else if (keycode == 45)
		d->depth = fmax(10, d->depth - 10);
	else if (keycode == 61)
		d->depth = fmin(MAX_DEPTH, d->depth + 10);
	else
		return (0);
	return (1);
}

static int	handle_movement_keys(int keycode, t_data *d)
{
	double	move_factor;

	move_factor = (3.5 / W) / d->zoom * 30;
	if (keycode == 65361 || keycode == 65363)
		d->offset_x += move_factor * ((keycode == 65363) * 2 - 1);
	else if (keycode == 65362 || keycode == 65364)
		d->offset_y += move_factor * ((keycode == 65364) * 2 - 1);
	else
		return (0);
	return (1);
}

void	handle_key_press(int keycode, t_data *d)
{
	if (keycode == 99)
	{
		d->color_idx = (d->color_idx + 1) % d->num_colors;
		d->color = get_color_profile(d->color_idx);
		redraw_image(d);
		return ;
	}
	if (handle_movement_keys(keycode, d))
		d->needs_recompute = 1;
	else if (handle_param_keys(keycode, d))
		d->needs_recompute = 1;
	else if (keycode == 116)
	{
		d->shift_colors = !d->shift_colors;
		d->needs_recompute = 1;
	}
}

int	key_hook(int keycode, t_data *d)
{
	if (keycode == 65307)
		close_hook(d);
	else
		handle_key_press(keycode, d);
	if (d->needs_recompute)
		draw_fractal(d);
	return (0);
}
