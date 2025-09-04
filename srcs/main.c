/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:34:49 by emoman            #+#    #+#             */
/*   Updated: 2025/09/04 15:54:34 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal_state(t_data *d)
{
	d->zoom = 1.0;
	if (d->type == MANDELBROT)
		d->offset_x = -0.75;
	else
		d->offset_x = 0.0;
	d->offset_y = 0.0;
	d->depth = 50;
	d->needs_recompute = 1;
	d->time = 0.0;
	d->shift_colors = 0;
	d->num_colors = count_color_profiles();
	d->color_idx = 0;
	d->color = get_color_profile(d->color_idx);
	d->julia_d = NULL;
	d->parent_d = NULL;
}

static int	init_graphics(t_data *d)
{
	char	window_title[256];

	d->iter = malloc(sizeof(double) * W * H);
	if (!d->iter)
		return (1);
	d->mlx = mlx_init();
	if (!d->mlx)
		return (free(d->iter), 1);
	build_title(window_title, d);
	d->win = mlx_new_window(d->mlx, W, H, window_title);
	if (!d->win)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
		free(d->iter);
		return (1);
	}
	d->img = mlx_new_image(d->mlx, W, H);
	if (!d->img)
		return (1);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel,
			&d->line_length, &d->endian);
	return (0);
}

static int	init_data(t_data *d)
{
	d->iter = NULL;
	d->mlx = NULL;
	d->win = NULL;
	d->img = NULL;
	if (init_graphics(d) != 0)
		return (1);
	init_fractal_state(d);
	return (0);
}

static void	cleanup_and_exit(t_data *d)
{
	if (d->julia_d)
	{
		mlx_destroy_image(d->julia_d->mlx, d->julia_d->img);
		mlx_destroy_window(d->julia_d->mlx, d->julia_d->win);
		free(d->julia_d->iter);
		free(d->julia_d);
	}
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	free(d->iter);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (!parse_args(argc, argv, &d))
	{
		print_usage();
		return (1);
	}
	if (init_data(&d))
	{
		ft_printf("Error: Failed to initialize data\n");
		return (1);
	}
	draw_fractal(&d);
	mlx_loop_hook(d.mlx, timer_hook, &d);
	mlx_hook(d.win, 2, 1L << 0, key_hook, &d);
	mlx_hook(d.win, 17, 1L << 17, close_hook, &d);
	mlx_hook(d.win, 6, 1L << 6, mouse_motion_hook, &d);
	mlx_mouse_hook(d.win, mouse_hook, &d);
	mlx_loop(d.mlx);
	cleanup_and_exit(&d);
	return (0);
}
