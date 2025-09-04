/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:45:17 by emoman            #+#    #+#             */
/*   Updated: 2025/09/04 15:45:19 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	append_julia_info(char *dst, int *i, t_data *d)
{
	const char	*name;
	const char	*equation_name;
	const char	*eq;

	name = d->preset_name;
	if (d->equation == Z_SQUARED)
		equation_name = "z^2";
	else if (d->equation == BURNING_SHIP)
		equation_name = "Burning Ship";
	else
		equation_name = "Tricorn";
	while (*name && *i < 255)
		dst[(*i)++] = *name++;
	dst[(*i)++] = ' ';
	dst[(*i)++] = '(';
	eq = equation_name;
	while (*eq && *i < 255)
		dst[(*i)++] = *eq++;
	dst[(*i)++] = ')';
}

static int	init_julia_data(t_data *m_data, t_data *j_data)
{
	char	title[256];

	j_data->type = JULIA;
	j_data->equation = m_data->equation;
	j_data->preset_name = "Custom";
	j_data->mlx = m_data->mlx;
	j_data->parent_d = m_data;
	j_data->julia_d = NULL;
	j_data->iter = malloc(sizeof(double) * W * H);
	if (!j_data->iter)
	{
		free(j_data);
		return (1);
	}
	build_title(title, j_data);
	j_data->win = mlx_new_window(j_data->mlx, W, H, title);
	j_data->img = mlx_new_image(j_data->mlx, W, H);
	j_data->addr = mlx_get_data_addr(j_data->img, &j_data->bits_per_pixel,
			&j_data->line_length, &j_data->endian);
	mlx_hook(j_data->win, 17, 1L << 17, julia_close_hook, j_data);
	mlx_hook(j_data->win, 2, 1L << 0, key_hook, j_data);
	mlx_hook(j_data->win, 6, 1L << 6, mouse_motion_hook, j_data);
	mlx_mouse_hook(j_data->win, mouse_hook, j_data);
	return (0);
}

static void	update_julia_params(t_data *j_data, t_data *m_data, t_complex c)
{
	j_data->type = JULIA;
	j_data->julia_c = c;
	j_data->color_idx = m_data->color_idx;
	j_data->color = get_color_profile(j_data->color_idx);
	j_data->num_colors = m_data->num_colors;
	j_data->shift_colors = m_data->shift_colors;
	j_data->zoom = 1.0;
	j_data->offset_x = 0.0;
	j_data->offset_y = 0.0;
	j_data->depth = 50;
	j_data->time = 0.0;
	j_data->needs_recompute = 1;
}

int	launch_julia_window(t_data *m_data, t_complex c)
{
	t_data	*j_data;

	if (isnan(c.x) || isnan(c.y) || isinf(c.x) || isinf(c.y))
		return (ft_printf("Error: Invalid Julia parameters\n"), 1);
	if (m_data->julia_d == NULL)
	{
		j_data = malloc(sizeof(t_data));
		if (!j_data)
			return (1);
		if (init_julia_data(m_data, j_data))
			return (1);
		m_data->julia_d = j_data;
	}
	j_data = m_data->julia_d;
	update_julia_params(j_data, m_data, c);
	draw_fractal(j_data);
	return (0);
}

int	julia_close_hook(t_data *j_data)
{
	t_data	*m_data;

	m_data = j_data->parent_d;
	m_data->julia_d = NULL;
	mlx_destroy_image(j_data->mlx, j_data->img);
	mlx_destroy_window(j_data->mlx, j_data->win);
	free(j_data->iter);
	free(j_data);
	return (0);
}
